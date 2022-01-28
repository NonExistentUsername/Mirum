#pragma once

#include <SFML/Graphics.hpp>

class IEventHandler {
protected:
    virtual void handle(const sf::Event& event) = 0;

    friend class IInputComponent;
};