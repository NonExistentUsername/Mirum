#pragma once

#include "../general/interfaces/controller.hpp"

class MainController : public IController {
public:
    void update() override;
    void draw(IRenderer* renderer) override;
};