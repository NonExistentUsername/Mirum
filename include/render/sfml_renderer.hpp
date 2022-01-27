#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/renderer.hpp"

class SFMLRenderer : public IRenderer {
protected:
    sf::RenderWindow* window = nullptr;

    friend class SFMLInputComponent;
public:
    SFMLRenderer();

    void display() override;

    ~SFMLRenderer();
};