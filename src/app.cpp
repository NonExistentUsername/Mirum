#include <cassert>

#include "app.hpp"
#include "render/interfaces/renderer.hpp"
#include "input/interfaces/input_component.hpp"
#include "controllers/interfaces/controller.hpp"
#include "window/interfaces/window.hpp"
#include "event_handling/event_handler.hpp"

void Application::update() {
    event_handler->update();
    controller->update();
}

void Application::redraw() {
    controller->draw(window->getRenderer());
}

void Application::init(IWindow* window) {
    this->window = window;
    this->event_handler = new EventHandler(window->getInput());
}

void Application::setController(IController* controller) {
    if(controller)
        delete controller;
    this->controller = controller;
}

void Application::game_loop() {
    assert(window != nullptr);
    assert(controller != nullptr);

    while(window->is_opened()) {
        update();
        redraw();
    }
}

EventHandler* Application::getEventHandler() const  {
    return this->event_handler;
}

void Application::close() {
    this->window->close();
}

Application::~Application() {
    if(window)
        delete window;
    if(controller)
        delete controller;
}