#pragma once

class Application;

class IRenderer {
public:
    virtual void display() = 0;
    virtual void clear() = 0;
};