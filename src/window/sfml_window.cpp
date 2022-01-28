#include "window/sfml_window.hpp"

SFMLWindow::SFMLWindow() {
    window = new sf::RenderWindow(sf::VideoMode(222, 222, 32), "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
}

IRenderer* SFMLWindow::getRenderer() {
    return (IRenderer*)renderer;
}

IInputComponent* SFMLWindow::getInput() {
    return (IInputComponent*)input;
}

SFMLWindow::~SFMLWindow() {
    delete window;
}

