#include "input/sfml_input_component.hpp"


SFMLInputComponent::SFMLInputComponent(sf::RenderWindow* window):
    window(window) {}

bool SFMLInputComponent::isKeyPressed(KEY_CODE key_code) {
    //TODO
    return false;
}

void SFMLInputComponent::handleEvents(const Command<void(const Event&)>& command) {
    sf::Event event;

    while (window->pollEvent(event))
    {

    }
}