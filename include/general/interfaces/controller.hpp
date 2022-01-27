#pragma once

class IRenderer;

class IController {
public:
    virtual void update() = 0;
    virtual void draw(IRenderer* renderer) = 0;
};