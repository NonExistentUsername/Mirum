#pragma once

class Renderer;
class Application {
private:
    Renderer* renderer = nullptr;
public:
    void init();
    void game_loop();
};