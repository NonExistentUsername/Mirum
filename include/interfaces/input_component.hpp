#pragma once

#include <SFML/Graphics.hpp>
#include "command.hpp"

class IInputComponent {
public:
    using EventType = sf::Event;
    virtual void update(const Command<void(const EventType&)>& command) = 0;
};