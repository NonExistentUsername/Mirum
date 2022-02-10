#pragma once

#include <SFML/Graphics.hpp>
#include "view_messages.hpp"
#include "math/rectangle.hpp"

class IEventFilter {
public:
    virtual VMESSAGE convert(const sf::Event& event, const Rect<long double>& canvas) = 0;
};