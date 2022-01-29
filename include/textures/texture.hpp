#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "itexture.hpp"

class Texture : public ITexture {
private:
    std::shared_ptr<sf::Texture> texture;
public:
    Texture(std::shared_ptr<sf::Texture> texture);
};