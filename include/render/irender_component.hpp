#pragma once

#include "irenderer.hpp"
class IRenderComponent {
private:
    using _weak_renderer_ptr = IRenderer*;
public:
    virtual void draw(_weak_renderer_ptr renderer) = 0;
}; 