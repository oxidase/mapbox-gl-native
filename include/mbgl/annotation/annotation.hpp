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

class PointAnnotationProperties {
public:
    std::string icon;
};

class LineAnnotationProperties {
public:
    float opacity = 1;
    float width = 1;
    Color color = {{ 0, 0, 0, 1 }};
};

class PolygonAnnotationProperties {
public:
    float opacity = 1;
    Color color = {{ 0, 0, 0, 1 }};
    Color outlineColor = {{ 0, 0, 0, -1 }};
};

// An annotation whose type and properties are sourced from a style layer.
struct StyleSourcedAnnotationProperties {
    std::string layerID;
};

using AnnotationProperties = variant<
    PointAnnotationProperties,
    LineAnnotationProperties,
    PolygonAnnotationProperties,
    StyleSourcedAnnotationProperties>;

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
