#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "tools/observer.hpp"
#include "math/rect.hpp"

class IRenderer;

class IViewComponent : public Observer<const sf::Event&> {
private:
    using _weak_renderer_ptr = IRenderer*;
protected:
    IViewComponent();
    IViewComponent(Rect<long double> canvas);
public:
    Rect<long double> canvas;

    virtual void draw(_weak_renderer_ptr renderer) = 0;
    virtual void addComponent(std::unique_ptr<IViewComponent> component);
    
    virtual void notify(const sf::Event& message) = 0;
    virtual ~IViewComponent();
};