#include "input/sfml_input_component.hpp"
#include "render/sfml_renderer.hpp"

SFMLInputComponent::SFMLInputComponent(const SFMLRenderer* const renderer):
    window(renderer->window) {}

void SFMLInputComponent::handleEvents(const IEventHandler* command) {
    sf::Event event;

    while (window->pollEvent(event)) {
        // if(event.type == sf::Event::EventType::)
    }
}