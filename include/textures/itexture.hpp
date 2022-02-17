#pragma once

#include "sprite_pool.hpp"
#include <memory>

class ITexture {
protected:
    static SpritePool sprite_pool;
    using _shared_texture = std::shared_ptr<sf::Texture>;

    _shared_texture texture;

    ITexture();
    ITexture(_shared_texture texture);
public:
    virtual SpriteSaver create_sprite() = 0;
};