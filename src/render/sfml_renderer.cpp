#include <SFML/Graphics.hpp>

#include "render/sfml_renderer.hpp"
#include "app.hpp"

SFMLRenderer::SFMLRenderer(sf::RenderWindow* window) {
    this->window = window;
}

void SFMLRenderer::drawTexture(_weak_texture texture) {
    //TODO
}

void SFMLRenderer::display() {
    window->display();
}
    
void SFMLRenderer::clear() {
    window->clear(sf::Color::White);
}