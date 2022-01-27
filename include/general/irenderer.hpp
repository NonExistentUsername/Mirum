#pragma once

class Application;

class IRenderer {
public:
    virtual void redraw(const Application& app) = 0;
};