#pragma once

#include "textures/texture.hpp"

class IRenderer {
protected:
    using _weak_texture = Texture*;
public:
    virtual void drawTexture(_weak_texture texture) = 0;

    virtual void display() = 0;
    virtual void clear() = 0;
};