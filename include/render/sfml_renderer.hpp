#pragma once

#include <SFML/Graphics.hpp>

#include "irenderer.hpp"

class SFMLRenderer : public IRenderer {
protected:
    using _weak_texture = Texture*;

    sf::RenderWindow* window = nullptr;

    friend class SFMLInputComponent;
public:
    SFMLRenderer(sf::RenderWindow* window);

    void drawTexture(_weak_texture texture) override;

    void display() override;
    void clear() override;
};