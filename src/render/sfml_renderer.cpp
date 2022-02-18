#include <SFML/Graphics.hpp>

#include "render/sfml_renderer.hpp"
#include "app.hpp"

SFMLRenderer::SFMLRenderer(sf::RenderWindow* window) {
    this->window = window;
}

void SFMLRenderer::draw_sprite(sf::Sprite& sprite) {
    this->window->draw(sprite);
}

void SFMLRenderer::display() {
    window->display();
}
    
void SFMLRenderer::clear() {
    window->clear(sf::Color::White);
}