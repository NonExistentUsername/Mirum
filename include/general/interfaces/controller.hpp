#pragma once

class IRenderer;
class Application;

class IController {
protected:
    Application* app = nullptr;
public:
    IController(Application* app): app(app) {}

    virtual void update() = 0;
    virtual void draw(IRenderer* renderer) = 0;
};