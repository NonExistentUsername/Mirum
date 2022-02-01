#include "view/button.hpp"

Button::Button(_unique_button_command_ptr command, _weak_render_component_ptr component):
    command(std::move(command)), component(component) {}

Button::Button(_unique_button_command_ptr command, _weak_render_component_ptr component, Rect<long double> canvas):
    IViewComponentLeaf(std::move(canvas)), command(std::move(command)), component(component) {}

void Button::notify(const sf::Event& message) {
    if(message.type == sf::Event::MouseButtonPressed) {
        command->pressed();
        this->notify_observers(VMESSAGE::BUTTON_PRESSED);
    } else
    if(message.type == sf::Event::MouseButtonReleased) {
        command->released();
        this->notify_observers(VMESSAGE::BUTTON_RELEASED);
    }
}