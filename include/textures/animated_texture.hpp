#pragma once

#include "ianimated_texture.hpp"

class AnimatedTexture : public IAnimatedTexture {
private:
public:
    AnimatedTexture(std::shared_ptr<sf::Texture> texture);
    
    SpriteSaver create_sprite() override;
};