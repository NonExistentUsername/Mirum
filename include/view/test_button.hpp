#pragma once

#include "view_component.hpp"
#include "ievent_filter.hpp"

class ButtonEventFilter : public IEventFilter {
public:
    VMESSAGE convert(const sf::Event& event, const Rect<long double>& canvas) override;
};

class Button : public ViewComponent {
public:
    Button();
    Button(Rect<long double> canvas);
};