#include "controllers/main_controller.hpp"
#include "input/iinput_component.hpp"
#include "input/ievent_handler.hpp"
#include "event_handling/event_handler.hpp"
#include "app.hpp"

#include <iostream>

AppCloser::AppCloser(Application* app):
    app(app) {}

void AppCloser::notify(const sf::Event& message) {
    std::cout << "Event Handler" << std::endl;
    app->close();
}

MainController::MainController(Application* app): 
    IController(app) {
    app->getEventHandler()->addHandler(sf::Event::EventType::Closed, new AppCloser(app));
}

void MainController::update() {
    //TODO
}

void MainController::draw(IRenderer* renderer) {
    //TODO
}