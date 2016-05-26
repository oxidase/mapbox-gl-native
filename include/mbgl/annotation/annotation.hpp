#pragma once

#include <mbgl/style/types.hpp>

#include <mbgl/util/geometry.hpp>
#include <mbgl/util/variant.hpp>

#include <cstdint>
#include <vector>
#include <string>

namespace mbgl {

using AnnotationID = uint32_t;
using AnnotationIDs = std::vector<AnnotationID>;

class PointAnnotation {
public:
    Point<double> geometry;
    std::string icon;
};

class LineAnnotation {
public:
    Line<double> geometry;
    float opacity = 1;
    float width = 1;
    Color color = {{ 0, 0, 0, 1 }};
};

class PolygonAnnotation {
public:
    Polygon<double> geometry;
    float opacity = 1;
    Color color = {{ 0, 0, 0, 1 }};
    Color outlineColor = {{ 0, 0, 0, -1 }};
};

// An annotation whose type and properties are sourced from a style layer.
struct StyleSourcedAnnotation {
    Geometry<double> geometry;
    std::string layerID;
};

using Annotation = variant<
    PointAnnotation,
    LineAnnotation,
    PolygonAnnotation,
    StyleSourcedAnnotation>;

//    AnnotationSegments wrapCoordinates(const AnnotationSegments& segments_) {
//        AnnotationSegments wrappedSegments;
//        // Wrap all segments coordinates.
//        for (const auto& segment_ : segments_) {
//            AnnotationSegment wrappedSegment;
//            for (const auto& latLng_ : segment_) {
//                wrappedSegment.push_back(latLng_.wrapped());
//            }
//            wrappedSegments.push_back(wrappedSegment);
//        }
//        return wrappedSegments;
//    }

} // namespace mbgl
