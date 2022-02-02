#include "view/icomponent_leaf.hpp"

ViewComponent::ViewComponent() {}
ViewComponent::ViewComponent(Rect<long double> canvas):
    IViewComponent(std::move(canvas)) {}

void ViewComponent::draw(_weak_renderer_ptr renderer) {
    //render_component.draw(decorate(renderer));
    //TODO
}

void ViewComponent::notify_observers(VMESSAGE message) {
    this->manager.notify(message);
}
    
ObserverKey<VMESSAGE> ViewComponent::add(_unique_observer_ptr observer) {
    return manager.add(std::move(observer));
}