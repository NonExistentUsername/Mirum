#pragma once

class IRenderer;
class Application;
class IInputComponent;

class IController {
protected:
    Application* app = nullptr;
public:
    IController(Application* app): app(app) {}

    virtual void update(IInputComponent* input_component) = 0;
    virtual void draw(IRenderer* renderer) = 0;
};