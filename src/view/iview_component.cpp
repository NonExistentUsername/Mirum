#include "view/iview_component.hpp"
#include <stdexcept>

IViewComponent::IViewComponent() {}
IViewComponent::IViewComponent(Rect<long double> canvas):
    canvas(canvas) {}

void IViewComponent::addComponent(std::unique_ptr<IViewComponent> component) {
    throw new std::logic_error("Not implemented method");
}

IViewComponent::~IViewComponent() {}