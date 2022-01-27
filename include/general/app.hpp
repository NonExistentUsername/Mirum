#pragma once

class IRenderer;
class Application {
private:
    IRenderer* renderer = nullptr;
public:
    void init();
    void game_loop();
};