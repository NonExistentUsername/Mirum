#include "view/icomponent_leaf.hpp"

IViewComponentLeaf::IViewComponentLeaf() {}
IViewComponentLeaf::IViewComponentLeaf(Rect<long double> canvas):
    IViewComponent(std::move(canvas)) {}

void IViewComponentLeaf::draw(_weak_renderer_ptr renderer) {
    //render_component.draw(decorate(renderer));
    //TODO
}

void IViewComponentLeaf::notify_observers(VMESSAGE message) {
    this->manager.notify(message);
}
    
ObserverKey<VMESSAGE> IViewComponentLeaf::add(_unique_observer_ptr observer) {
    return manager.add(std::move(observer));
}