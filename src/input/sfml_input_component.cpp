#include "input/sfml_input_component.hpp"
#include "render/sfml_renderer.hpp"
#include "input/interfaces/event_handler.hpp"

SFMLInputComponent::SFMLInputComponent(sf::RenderWindow* window):
    window(window) {}

void SFMLInputComponent::handleEvents(IEventHandler* command) {
    sf::Event event;

    while (window->pollEvent(event)) {
        command->handle(event);
    }
}