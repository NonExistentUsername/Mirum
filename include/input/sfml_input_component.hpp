#pragma once

#include <SFML/Graphics.hpp>

#include "interfaces/input_component.hpp"

class IEventHandler;
class SFMLRenderer;

class SFMLInputComponent : public IInputComponent {
private:
    sf::RenderWindow* window;
public:
    SFMLInputComponent(sf::RenderWindow* window);

    void handleEvents(const IEventHandler* command) override;
};