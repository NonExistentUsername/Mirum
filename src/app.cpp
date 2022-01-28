#include <cassert>

#include "app.hpp"
#include "render/interfaces/renderer.hpp"
#include "input/interfaces/input_component.hpp"
#include "controllers/interfaces/controller.hpp"
#include "window/interfaces/window.hpp"

void Application::update() {
    controller->update(window->getInput());
}

void Application::redraw() {
    controller->draw(window->getRenderer());
}

void Application::init(IWindow* window) {
    this->window = window;
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

void Application::close() {
    this->window->close();
}

Application::~Application() {
    if(window)
        delete window;
    if(controller)
        delete controller;
}