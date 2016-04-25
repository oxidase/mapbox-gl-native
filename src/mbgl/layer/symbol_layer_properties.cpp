// This file is generated. Do not edit.

#include <mbgl/layer/symbol_layer_properties.hpp>

namespace mbgl {

void SymbolLayoutProperties::parse(const JSValue& value) {
    symbolPlacement.parse("symbol-placement", value);
    symbolSpacing.parse("symbol-spacing", value);
    symbolAvoidEdges.parse("symbol-avoid-edges", value);
    iconAllowOverlap.parse("icon-allow-overlap", value);
    iconIgnorePlacement.parse("icon-ignore-placement", value);
    iconOptional.parse("icon-optional", value);
    iconRotationAlignment.parse("icon-rotation-alignment", value);
    iconSize.parse("icon-size", value);
    iconImage.parse("icon-image", value);
    iconRotate.parse("icon-rotate", value);
    iconPadding.parse("icon-padding", value);
    iconKeepUpright.parse("icon-keep-upright", value);
    iconOffset.parse("icon-offset", value);
    textRotationAlignment.parse("text-rotation-alignment", value);
    textField.parse("text-field", value);
    textFont.parse("text-font", value);
    textSize.parse("text-size", value);
    textMaxWidth.parse("text-max-width", value);
    textLineHeight.parse("text-line-height", value);
    textLetterSpacing.parse("text-letter-spacing", value);
    textJustify.parse("text-justify", value);
    textAnchor.parse("text-anchor", value);
    textMaxAngle.parse("text-max-angle", value);
    textRotate.parse("text-rotate", value);
    textPadding.parse("text-padding", value);
    textKeepUpright.parse("text-keep-upright", value);
    textTransform.parse("text-transform", value);
    textOffset.parse("text-offset", value);
    textAllowOverlap.parse("text-allow-overlap", value);
    textIgnorePlacement.parse("text-ignore-placement", value);
    textOptional.parse("text-optional", value);
}

void SymbolPaintProperties::parse(const JSValue& value) {
    iconOpacity.parse("icon-opacity", value);
    iconColor.parse("icon-color", value);
    iconHaloColor.parse("icon-halo-color", value);
    iconHaloWidth.parse("icon-halo-width", value);
    iconHaloBlur.parse("icon-halo-blur", value);
    iconTranslate.parse("icon-translate", value);
    iconTranslateAnchor.parse("icon-translate-anchor", value);
    textOpacity.parse("text-opacity", value);
    textColor.parse("text-color", value);
    textHaloColor.parse("text-halo-color", value);
    textHaloWidth.parse("text-halo-width", value);
    textHaloBlur.parse("text-halo-blur", value);
    textTranslate.parse("text-translate", value);
    textTranslateAnchor.parse("text-translate-anchor", value);
}

void SymbolPaintProperties::cascade(const StyleCascadeParameters& parameters) {
    iconOpacity.cascade(parameters);
    iconColor.cascade(parameters);
    iconHaloColor.cascade(parameters);
    iconHaloWidth.cascade(parameters);
    iconHaloBlur.cascade(parameters);
    iconTranslate.cascade(parameters);
    iconTranslateAnchor.cascade(parameters);
    textOpacity.cascade(parameters);
    textColor.cascade(parameters);
    textHaloColor.cascade(parameters);
    textHaloWidth.cascade(parameters);
    textHaloBlur.cascade(parameters);
    textTranslate.cascade(parameters);
    textTranslateAnchor.cascade(parameters);
}

bool SymbolPaintProperties::recalculate(const StyleCalculationParameters& parameters) {
    bool hasTransitions = false;

    hasTransitions |= iconOpacity.calculate(parameters);
    hasTransitions |= iconColor.calculate(parameters);
    hasTransitions |= iconHaloColor.calculate(parameters);
    hasTransitions |= iconHaloWidth.calculate(parameters);
    hasTransitions |= iconHaloBlur.calculate(parameters);
    hasTransitions |= iconTranslate.calculate(parameters);
    hasTransitions |= iconTranslateAnchor.calculate(parameters);
    hasTransitions |= textOpacity.calculate(parameters);
    hasTransitions |= textColor.calculate(parameters);
    hasTransitions |= textHaloColor.calculate(parameters);
    hasTransitions |= textHaloWidth.calculate(parameters);
    hasTransitions |= textHaloBlur.calculate(parameters);
    hasTransitions |= textTranslate.calculate(parameters);
    hasTransitions |= textTranslateAnchor.calculate(parameters);

    return hasTransitions;
}

} // namespace mbgl
