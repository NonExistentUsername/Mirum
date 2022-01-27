#include "input/sfml_input_component.hpp"
#include "render/sfml_renderer.hpp"

SFMLInputComponent::SFMLInputComponent(const SFMLRenderer* const renderer):
    window(renderer->window) {}

bool SFMLInputComponent::isKeyPressed(KEY_CODE key_code) {
    //TODO
    return false;
}

void SFMLInputComponent::handleEvents(const IEventHandler* command) {
    sf::Event event;

    while (window->pollEvent(event))
    {

    }
}