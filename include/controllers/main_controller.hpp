#pragma once

#include "interfaces/controller.hpp"

class MainController : public IController {
public:
    MainController(Application* app): IController(app) {}

    void update(IInputComponent* input_component) override;
    void draw(IRenderer* renderer) override;
};