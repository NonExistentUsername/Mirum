#include "textures/itexture.hpp"

ITexture::ITexture() {}

ITexture::ITexture(_shared_texture texture):
    texture(texture) {}