#include "view/view_observer.hpp"

void ViewObserver::notify(const sf::Event& message) {
    this->component->notify(message);
}

ViewObserver::ViewObserver(_weak_iview_component component):
    component(component) {}