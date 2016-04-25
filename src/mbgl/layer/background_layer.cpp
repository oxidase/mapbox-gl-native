// This file is generated. Do not edit.

#include <mbgl/layer/background_layer.hpp>
#include <mbgl/layer/background_layer_impl.hpp>

namespace mbgl {

BackgroundLayer::BackgroundLayer(const std::string& layerID)
    : Layer(Type::Background, std::make_unique<Impl>())
    , impl(static_cast<Impl*>(baseImpl.get())) {
    impl->id = layerID;
}

BackgroundLayer::BackgroundLayer(const BackgroundLayer& other)
    : Layer(Type::Background, std::make_unique<Impl>(*other.impl))
    , impl(static_cast<Impl*>(baseImpl.get())) {
}

BackgroundLayer::~BackgroundLayer() = default;

std::unique_ptr<Layer> BackgroundLayer::clone() const {
    return std::make_unique<BackgroundLayer>(*this);
}


// Layout properties


// Paint properties

Function<Color> BackgroundLayer::getBackgroundColor() const {
    return impl->paint.backgroundColor.values.at(ClassID::Default);
}

void BackgroundLayer::setBackgroundColor(Function<Color> value) {
    impl->paint.backgroundColor.values.emplace(ClassID::Default, value);
}

Function<std::string> BackgroundLayer::getBackgroundPattern() const {
    return impl->paint.backgroundPattern.values.at(ClassID::Default);
}

void BackgroundLayer::setBackgroundPattern(Function<std::string> value) {
    impl->paint.backgroundPattern.values.emplace(ClassID::Default, value);
}

Function<float> BackgroundLayer::getBackgroundOpacity() const {
    return impl->paint.backgroundOpacity.values.at(ClassID::Default);
}

void BackgroundLayer::setBackgroundOpacity(Function<float> value) {
    impl->paint.backgroundOpacity.values.emplace(ClassID::Default, value);
}

} // namespace mbgl
