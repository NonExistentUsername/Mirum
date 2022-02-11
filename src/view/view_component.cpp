#include "view/view_component.hpp"

ViewComponent::ViewComponent(_weak_controller_ptr filter):
    filter(filter) {}
ViewComponent::ViewComponent(_weak_controller_ptr filter, Rect<long double> canvas):
    filter(filter), IViewComponent(std::move(canvas)) {}

void ViewComponent::draw(_weak_renderer_ptr renderer) {
    //render_component.draw(decorate(renderer));
    //TODO
}

void ViewComponent::notify(const sf::Event& message) {
    this->notify_observers(filter->convert(message, canvas));
}

void ViewComponent::notify_observers(VMESSAGE message) {
    this->manager.notify(message);
}
    
ObserverKey<VMESSAGE> ViewComponent::add(_unique_observer_ptr observer) {
    return manager.add(std::move(observer));
}

ViewComponent::~ViewComponent() {}