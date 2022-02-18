#pragma once

#include <SFML/Graphics.hpp>

#include "irenderer.hpp"

class SFMLRenderer : public IRenderer {
protected:
    sf::RenderWindow* window = nullptr;

    friend class SFMLInputComponent;
public:
    SFMLRenderer(sf::RenderWindow* window);

    void draw_sprite(sf::Sprite& sprite) override;

    void display() override;
    void clear() override;
};