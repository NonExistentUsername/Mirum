#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "itexture.hpp"

class Texture : public ITexture {
private:
public:
    Texture(std::shared_ptr<sf::Texture> texture);
    
    SpriteSaver create_sprite() override;
};