#pragma once

#include <SFML/Graphics.hpp>

class IEventHandler {
public:
    virtual void handle(const sf::Event& event) = 0;
};