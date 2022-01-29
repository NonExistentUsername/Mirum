#pragma once

#include <SFML/Graphics.hpp>
#include "iinput_component.hpp"

class IEventHandler;
class SFMLRenderer;

class SFMLInputComponent : public IInputComponent {
private:
    using _weak_observer_ptr = Observer<const sf::Event&>*;

    sf::RenderWindow* window;
public:
    SFMLInputComponent(sf::RenderWindow* window);

    void handleEvents(_weak_observer_ptr handler) override;
};