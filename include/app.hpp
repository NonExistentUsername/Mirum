#pragma once

class IRenderer;
class IController;
class Application {
private:
    IRenderer* renderer = nullptr;
    IController* controller = nullptr;


    void update();
    void redraw();
public:
    void init(IController* controller);
    void game_loop();

    ~Application();
};