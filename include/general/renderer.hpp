#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/renderer.hpp"

class Renderer : public IRenderer {
private:
    sf::RenderWindow* window = nullptr;
public:
    Renderer();

    void redraw(const Application& app) override;

    ~Renderer();
};