#include <mbgl/layer/line_layer_impl.hpp>
#include <mbgl/style/style_bucket_parameters.hpp>
#include <mbgl/renderer/line_bucket.hpp>
#include <mbgl/map/tile_id.hpp>
#include <mbgl/util/get_geometries.hpp>
#include <mbgl/geometry/feature_index.hpp>
#include <mbgl/util/math.hpp>
#include <mbgl/util/intersection_tests.hpp>

namespace mbgl {

void LineLayer::Impl::parseLayout(const JSValue& value) {
    layout.parse(value);
}

void LineLayer::Impl::parsePaints(const JSValue& layer) {
    paint.parse(layer);
}

void LineLayer::Impl::cascade(const StyleCascadeParameters& parameters) {
    paint.cascade(parameters);
}

bool LineLayer::Impl::recalculate(const StyleCalculationParameters& parameters) {
    // for scaling dasharrays
    StyleCalculationParameters dashArrayParams = parameters;
    dashArrayParams.z = std::floor(dashArrayParams.z);
    paint.lineWidth.calculate(dashArrayParams);
    dashLineWidth = paint.lineWidth;

    bool hasTransitions = paint.recalculate(parameters);

    passes = (paint.lineOpacity > 0 && paint.lineColor.value[3] > 0 && paint.lineWidth > 0)
        ? RenderPass::Translucent : RenderPass::None;

    return hasTransitions;
}

std::unique_ptr<Bucket> LineLayer::Impl::createBucket(StyleBucketParameters& parameters) const {
    auto bucket = std::make_unique<LineBucket>(parameters.tileID.overscaleFactor());

    bucket->layout = layout;

    StyleCalculationParameters p(parameters.tileID.z);
    bucket->layout.lineCap.calculate(p);
    bucket->layout.lineJoin.calculate(p);
    bucket->layout.lineMiterLimit.calculate(p);
    bucket->layout.lineRoundLimit.calculate(p);

    auto& name = bucketName();
    parameters.eachFilteredFeature(filter, [&] (const auto& feature, std::size_t index, const std::string& layerName) {
        auto geometries = getGeometries(feature);
        bucket->addGeometry(geometries);
        parameters.featureIndex.insert(geometries, index, layerName, name);
    });

    return std::move(bucket);
}

float LineLayer::Impl::getLineWidth() const {
    if (paint.lineGapWidth > 0) {
        return paint.lineGapWidth + 2 * paint.lineWidth;
    } else {
        return paint.lineWidth;
    }
}

optional<GeometryCollection> offsetLine(const GeometryCollection& rings, const float offset) {
    if (offset == 0) return {};

    GeometryCollection newRings;
    vec2<double> zero(0, 0);
    for (auto& ring : rings) {
        newRings.emplace_back();
        auto& newRing = newRings.back();

        for (auto i = ring.begin(); i != ring.end(); i++) {
            auto& p = *i;

            auto aToB = i == ring.begin() ?
                zero :
                util::perp(util::unit(vec2<double>(p - *(i - 1))));
            auto bToC = i + 1 == ring.end() ?
                zero :
                util::perp(util::unit(vec2<double>(*(i + 1) - p)));
            auto extrude = util::unit(aToB + bToC);

            const double cosHalfAngle = extrude.x * bToC.x + extrude.y * bToC.y;
            extrude *= (1.0 / cosHalfAngle);

            newRing.push_back((extrude * offset) + p);
        }
    }

    return newRings;
}

float LineLayer::Impl::getQueryRadius() const {
    const std::array<float, 2>& translate = paint.lineTranslate;
    return getLineWidth() / 2.0 + std::abs(paint.lineOffset) + util::length(translate[0], translate[1]);
}

bool LineLayer::Impl::queryIntersectsGeometry(
        const GeometryCollection& queryGeometry,
        const GeometryCollection& geometry,
        const float bearing,
        const float pixelsToTileUnits) const {

    const float halfWidth = getLineWidth() / 2.0 * pixelsToTileUnits;

    auto translatedQueryGeometry = FeatureIndex::translateQueryGeometry(
            queryGeometry, paint.lineTranslate, paint.lineTranslateAnchor, bearing, pixelsToTileUnits);
    auto offsetGeometry = offsetLine(geometry, paint.lineOffset * pixelsToTileUnits);

    return util::multiPolygonIntersectsBufferedMultiLine(
            translatedQueryGeometry.value_or(queryGeometry),
            offsetGeometry.value_or(geometry),
            halfWidth);
}

} // namespace mbgl
