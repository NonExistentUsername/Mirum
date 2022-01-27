#include <SFML/Graphics.hpp>

#include "general/renderer.hpp"
#include "general/app.hpp"

Renderer::Renderer() {
    window = new sf::RenderWindow(sf::VideoMode(222, 222, 32), "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
}

void Renderer::display() {
    window->display();
}

Renderer::~Renderer() {
    delete window;
}