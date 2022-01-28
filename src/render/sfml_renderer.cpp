#include <SFML/Graphics.hpp>

#include "render/sfml_renderer.hpp"
#include "app.hpp"

SFMLRenderer::SFMLRenderer(sf::RenderWindow* window) {
    this->window = window;
}

void SFMLRenderer::display() {
    window->display();
}