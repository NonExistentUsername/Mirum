#pragma once

class IRenderer;
class IInputComponent;

class Window {
public:
    virtual IRenderer* getRenderer() = 0;
    virtual IInputComponent* getInput() = 0;
};