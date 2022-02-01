#include "view/menu.hpp"

void Menu::draw(_weak_renderer_ptr renderer) {
    for(auto& component : components)
        component->draw(renderer);
}

void Menu::addComponent(_unique_component_ptr component) {
    components.push_back(std::move(component));
}

void Menu::notify(const sf::Event& message) {
    for(auto& component : components)
        component->notify(message);
}