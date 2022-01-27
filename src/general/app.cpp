#include "general/app.hpp"
#include "general/renderer.hpp"

void Application::init() {
    renderer = new Renderer();
}

void Application::game_loop() {
    //TODO
}

Application::~Application() {
    if(renderer)
        delete renderer;
}