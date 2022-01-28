#include <cassert>
#include "window/sfml_window.hpp"
#include "render/sfml_renderer.hpp"
#include "input/sfml_input_component.hpp"

SFMLWindow::SFMLWindow() {
    window = new sf::RenderWindow(sf::VideoMode(600, 800, 32), "Mirum",
                            sf::Style::Titlebar | sf::Style::Close);
    renderer = new SFMLRenderer(window);
    input = new SFMLInputComponent(window);
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

