#pragma once

#include "irenderer.hpp"

class Renderer : public IRenderer {
public:
    Renderer();

    void redraw(const Application& app) override;
};