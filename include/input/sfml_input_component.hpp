#pragma once

#include <SFML/Graphics.hpp>

#include "iinput_component.hpp"

class IEventHandler;
class SFMLRenderer;

class SFMLInputComponent : public IInputComponent {
private:
    sf::RenderWindow* window;
public:
    SFMLInputComponent(sf::RenderWindow* window);

    void handleEvents(IEventHandler* command) override;
};