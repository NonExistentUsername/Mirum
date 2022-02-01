#include "textures/animated_texture.hpp"

AnimatedTexture::AnimatedTexture(std::shared_ptr<sf::Texture> texture):
    texture(texture) {}

void AnimatedTexture::draw(_weak_renderer_ptr renderer) {
    //TODO
}