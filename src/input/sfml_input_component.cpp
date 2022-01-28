#include "input/sfml_input_component.hpp"
#include "render/sfml_renderer.hpp"

SFMLInputComponent::SFMLInputComponent(sf::RenderWindow* window):
    window(window) {}

void SFMLInputComponent::handleEvents(const IEventHandler* command) {
    sf::Event event;

    while (window->pollEvent(event)) {
        // if(event.type == sf::Event::EventType::)
    }
}