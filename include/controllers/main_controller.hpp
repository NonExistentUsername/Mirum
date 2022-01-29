#pragma once

#include <SFML/Graphics.hpp>
#include "icontroller.hpp"
#include "tools/observer.hpp"

class AppCloser : public Observer<const sf::Event&> {
private:
    using _waek_app_ptr = Application*;

    _waek_app_ptr app;
public:
    AppCloser(_waek_app_ptr app);

    void notify(const sf::Event& message) override;
};

class MainController : public IController {
private:
    using _waek_app_ptr = Application*;
    using _waek_renderer_ptr = IRenderer*;
public:
    MainController(_waek_app_ptr app);

    void update() override;
    void draw(_waek_renderer_ptr renderer) override;
};