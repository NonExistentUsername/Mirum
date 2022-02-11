#include "view/test_button.hpp"

VMESSAGE ButtonEventFilter::convert(const sf::Event& event, const Rect<long double>& canvas) {
    if(event.type == sf::Event::MouseButtonPressed && canvas.contains(Vec(event.mouseButton.x, event.mouseButton.y)))
        return VMESSAGE::BUTTON_PRESSED;
    else
    if(event.type == sf::Event::MouseButtonReleased && canvas.contains(Vec(event.mouseButton.x, event.mouseButton.y)))
        return VMESSAGE::BUTTON_RELEASED;
    return VMESSAGE::UNKNOWN;
}