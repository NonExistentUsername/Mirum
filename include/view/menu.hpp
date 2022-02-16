#pragma once

#include <vector>
#include "iview_component.hpp"

class Menu : public IViewComponent {
private:
    using _weak_renderer_ptr = IRenderer*;
    using _unique_component_ptr = std::unique_ptr<IViewComponent>;

    std::vector<_unique_component_ptr> components;
public:
    void draw(_weak_renderer_ptr renderer) override;
    void addComponent(_unique_component_ptr component) override;
    
    void notify(const sf::Event& message) override;
};