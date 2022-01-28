#pragma once

#include <SFML/Graphics.hpp>
#include "icontroller.hpp"
#include "event_handling/key.hpp"
#include "tools/observer.hpp"

class AppCloser : public Observer<const sf::Event&> {
private:
    Application* app;
public:
    AppCloser(Application* app);

    void notify(const sf::Event& message) override;
};

class MainController : public IController {
public:
    MainController(Application* app);

    void update() override;
    void draw(IRenderer* renderer) override;
};