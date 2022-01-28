#pragma once

class IRenderer;
class IInputComponent;

class IWindow {
public:
    virtual IRenderer* getRenderer() = 0;
    virtual IInputComponent* getInput() = 0;
};