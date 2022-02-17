#include "textures/ianimated_texture.hpp"

IAnimatedTexture::IAnimatedTexture() {}

IAnimatedTexture::IAnimatedTexture(_shared_texture texture):
    ITexture(texture) {}