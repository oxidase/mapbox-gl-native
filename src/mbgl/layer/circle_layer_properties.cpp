// This file is generated. Do not edit.

#include <mbgl/layer/circle_layer_properties.hpp>

namespace mbgl {

void CirclePaintProperties::parse(const JSValue& value) {
    circleRadius.parse("circle-radius", value);
    circleColor.parse("circle-color", value);
    circleBlur.parse("circle-blur", value);
    circleOpacity.parse("circle-opacity", value);
    circleTranslate.parse("circle-translate", value);
    circleTranslateAnchor.parse("circle-translate-anchor", value);
}

void CirclePaintProperties::cascade(const StyleCascadeParameters& parameters) {
    circleRadius.cascade(parameters);
    circleColor.cascade(parameters);
    circleBlur.cascade(parameters);
    circleOpacity.cascade(parameters);
    circleTranslate.cascade(parameters);
    circleTranslateAnchor.cascade(parameters);
}

bool CirclePaintProperties::recalculate(const StyleCalculationParameters& parameters) {
    bool hasTransitions = false;

    hasTransitions |= circleRadius.calculate(parameters);
    hasTransitions |= circleColor.calculate(parameters);
    hasTransitions |= circleBlur.calculate(parameters);
    hasTransitions |= circleOpacity.calculate(parameters);
    hasTransitions |= circleTranslate.calculate(parameters);
    hasTransitions |= circleTranslateAnchor.calculate(parameters);

    return hasTransitions;
}

} // namespace mbgl
