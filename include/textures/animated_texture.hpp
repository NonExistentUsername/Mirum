#pragma once

#include "ianimated_texture.hpp"

class AnimatedTexture : public IAnimatedTexture {
private:
    std::shared_ptr<sf::Texture> texture;
public:
    AnimatedTexture(std::shared_ptr<sf::Texture> texture);
};