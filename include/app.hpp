#pragma once

class IWindow;
class IController;

class Application {
private:
    IWindow* window = nullptr;
    IController* controller = nullptr;

    void update();
    void redraw();
public:
    void init(IWindow* window);
    void game_loop();

    void setController(IController* controller);
    void close();

    ~Application();
};