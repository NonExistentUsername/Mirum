#pragma once

#include "icomponent_leaf.hpp"
#include "textures/itexture.hpp"
#include "render/irender_component.hpp"
#include <memory>

class Button : public IViewComponentLeaf {
private:
    using _unique_button_command_ptr = std::unique_ptr<IButtonController>;
    using _weak_render_component_ptr = IRenderComponent*;

    _unique_button_command_ptr command;
    _weak_render_component_ptr component;

    Button(_unique_button_command_ptr command, _weak_render_component_ptr component);
    Button(_unique_button_command_ptr command, _weak_render_component_ptr component, Rect<long double> canvas);
public:
    void notify(const sf::Event& message) override;
};