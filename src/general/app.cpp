#include "general/app.hpp"
#include "general/sfml_renderer.hpp"
#include "general/interfaces/controller.hpp"

void Application::update() {
    controller->update();
}

void Application::redraw() {
    controller->draw(renderer);
}

void Application::init(IController* controller) {
    renderer = new SFMLRenderer();
    this->controller = controller;
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