#pragma once

#include <SFML/Graphics.hpp>
#include "tools/observer.hpp"

class IInputComponent {
private:
    using _weak_observer_ptr = Observer<const sf::Event&>*;
public:
    virtual void handleEvents(_weak_observer_ptr handler) = 0;
};