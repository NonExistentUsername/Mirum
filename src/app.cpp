#include "app.hpp"
#include "render/sfml_renderer.hpp"
#include "controllers/interfaces/controller.hpp"

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