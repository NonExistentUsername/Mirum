#include <cassert>
#include "window/sfml_window.hpp"

SFMLWindow::SFMLWindow() {
    window = new sf::RenderWindow(sf::VideoMode(222, 222, 32), "Mirum",
                            sf::Style::Titlebar | sf::Style::Close);
}

IRenderer* SFMLWindow::getRenderer() {
    assert(window != nullptr);
    return (IRenderer*)renderer;
}

IInputComponent* SFMLWindow::getInput() {
    assert(window != nullptr);
    return (IInputComponent*)input;
}

bool SFMLWindow::is_opened() {
    return window->isOpen();
}

void SFMLWindow::close() {
    window->close();
}

SFMLWindow::~SFMLWindow() {
    delete window;
}

