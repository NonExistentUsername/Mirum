#include "controllers/main_controller.hpp"
#include "input/iinput_component.hpp"
#include "event_handling/event_handler.hpp"
#include "app.hpp"
#include "view/view_observer.hpp"

#include <iostream>

AppCloser::AppCloser(Application* app):
    app(app) {}

void AppCloser::notify(const sf::Event& message) {
    app->close();
}

MainController::MainController(Application* app): 
    IController(app) {
    app->getEventHandler()->addHandler(std::unique_ptr<Observer<const sf::Event&>>(new ViewObserver(&main_menu)));
    app->getEventHandler()->addHandler(sf::Event::EventType::Closed, std::unique_ptr<Observer<const sf::Event&>>(new AppCloser(app)));
}

void MainController::update() {
    //TODO
}

void MainController::draw(IRenderer* renderer) {
    //TODO
}