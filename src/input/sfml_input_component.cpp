#include "input/sfml_input_component.hpp"
#include "render/sfml_renderer.hpp"

SFMLInputComponent::SFMLInputComponent(sf::RenderWindow* window):
    window(window) {}

void SFMLInputComponent::handleEvents(_weak_observer_ptr handler) {
    sf::Event event;

    while (window->pollEvent(event)) {
        handler->notify(event);
    }
}