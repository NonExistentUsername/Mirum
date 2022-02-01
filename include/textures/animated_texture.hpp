#pragma once

#include "ianimated_texture.hpp"

class AnimatedTexture : public IAnimatedTexture {
private:
    using _weak_renderer_ptr = IRenderer*;
    
    std::shared_ptr<sf::Texture> texture;
public:
    AnimatedTexture(std::shared_ptr<sf::Texture> texture);
    
    void draw(_weak_renderer_ptr renderer) override;
};