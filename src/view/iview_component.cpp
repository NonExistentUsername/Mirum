#include "view/iview_component.hpp"
#include <stdexcept>

IViewComponent::IViewComponent() {}

void IViewComponent::draw(_weak_renderer_ptr renderer) {
    throw new std::logic_error("Not implemented method");   
}

void IViewComponent::addComponent(std::unique_ptr<IViewComponent> component) {
    throw new std::logic_error("Not implemented method");
}

void IViewComponent::notify(const sf::Event& message) {
    throw new std::logic_error("Not implemented method");    
}

IViewComponent::~IViewComponent() {}