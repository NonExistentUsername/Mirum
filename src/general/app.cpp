#include "general/app.hpp"
#include "general/renderer.hpp"
#include "general/interfaces/controller.hpp"

void Application::update() {
    controller->update();
}

void Application::redraw() {
    controller->draw(renderer);
}

void Application::init() {
    renderer = new Renderer();
}

void Application::game_loop() {
    while(true) {
        update();
        redraw();
    }
}

Application::~Application() {
    if(renderer)
        delete renderer;
}