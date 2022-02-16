#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "tools/observer.hpp"
#include "math/rect.hpp"

class IRenderer;

class IViewComponent {
private:
    using _weak_renderer_ptr = IRenderer*;
protected:
    IViewComponent();
public:
    virtual void draw(_weak_renderer_ptr renderer);
    virtual void addComponent(std::unique_ptr<IViewComponent> component);
    virtual void notify(const sf::Event& message);
    virtual ~IViewComponent();
};