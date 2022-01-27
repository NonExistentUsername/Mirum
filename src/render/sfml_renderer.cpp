#include <SFML/Graphics.hpp>

#include "render/sfml_renderer.hpp"
#include "app.hpp"

SFMLRenderer::SFMLRenderer() {
    window = new sf::RenderWindow(sf::VideoMode(222, 222, 32), "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
}

void SFMLRenderer::display() {
    window->display();
}

SFMLRenderer::~SFMLRenderer() {
    delete window;
}