#pragma once

class IRenderer;
class IController;
class IInputComponent;

class Application {
private:
    IInputComponent* input_component = nullptr;
    IRenderer* renderer = nullptr;
    IController* controller = nullptr;

    void update();
    void redraw();
public:
    void init(IRenderer* renderer, IInputComponent* input_component);
    void game_loop();

    void setController(IController* controller);

    ~Application();
};