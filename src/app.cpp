#include <cassert>

#include "app.hpp"
#include "render/irenderer.hpp"
#include "input/iinput_component.hpp"
#include "controllers/icontroller.hpp"
#include "window/iwindow.hpp"
#include "event_handling/event_handler.hpp"

void Application::update() {
    event_handler->update();
    controller->update();
}

void Application::redraw() {
    window->getRenderer()->clear();
    controller->draw(window->getRenderer());
    window->getRenderer()->display();
}

void Application::init(IWindow* window) {
    this->window = window;
    this->event_handler = new EventHandler(window->getInput());
}

void Application::setController(IController* controller) {
    if(this->controller)
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
    if(event_handler)
        delete event_handler;
}