#pragma once

#include <SFML/Graphics.hpp>

class IRenderer {
public:
    virtual void draw_sprite(sf::Sprite& sprite) = 0;

    virtual void display() = 0;
    virtual void clear() = 0;
};