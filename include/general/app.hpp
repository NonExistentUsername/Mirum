#pragma once

#include "renderer.hpp"
class Application {
private:
    Renderer* renderer = nullptr;
public:
    void init();
    void game_loop();
};