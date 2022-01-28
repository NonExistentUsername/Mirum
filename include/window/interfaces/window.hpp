#pragma once

class IRenderer;
class IInputComponent;

class IWindow {
public:
    virtual IRenderer* getRenderer() = 0;
    virtual IInputComponent* getInput() = 0;
    
    virtual bool is_opened() = 0;
    virtual void close() = 0;
};