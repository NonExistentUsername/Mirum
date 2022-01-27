#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/renderer.hpp"

class SFMLRenderer : public IRenderer {
private:
    sf::RenderWindow* window = nullptr;
public:
    SFMLRenderer();

    void display() override;

    ~SFMLRenderer();
};