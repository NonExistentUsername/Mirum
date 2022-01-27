#include <cassert>

#include "app.hpp"
#include "render/interfaces/renderer.hpp"
#include "input/interfaces/input_component.hpp"
#include "controllers/interfaces/controller.hpp"

void Application::update() {
    controller->update(this->input_component);
}

void Application::redraw() {
    controller->draw(renderer);
}

void Application::init(IRenderer* renderer, IInputComponent* input_component) {
    this->renderer = renderer;
    this->input_component = input_component;
}

void Application::setController(IController* controller) {
    if(controller)
        delete controller;
    this->controller = controller;
}

void Application::game_loop() {
    assert(input_component != nullptr);
    assert(renderer != nullptr);
    assert(controller != nullptr);

    while(true) {
        update();
        redraw();
    }
}

Application::~Application() {
    if(renderer)
        delete renderer;
    if(controller)
        delete controller;
    if(input_component)
        delete input_component;
}