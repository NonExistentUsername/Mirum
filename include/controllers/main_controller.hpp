#pragma once

#include "../general/interfaces/controller.hpp"

class MainController : public IController {
public:
    MainController(Application* app): IController(app) {}

    void update() override;
    void draw(IRenderer* renderer) override;
};