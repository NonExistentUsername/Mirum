#pragma once

#include <SFML/Graphics.hpp>

#include "irenderer.hpp"

class SFMLRenderer : public IRenderer {
protected:
    sf::RenderWindow* window = nullptr;

    friend class SFMLInputComponent;
public:
    SFMLRenderer(sf::RenderWindow* window);

    void display() override;
    void clear() override;
};