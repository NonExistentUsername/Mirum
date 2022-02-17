#include "textures/animated_texture.hpp"

AnimatedTexture::AnimatedTexture(std::shared_ptr<sf::Texture> texture):
    IAnimatedTexture(texture) {}
    
SpriteSaver AnimatedTexture::create_sprite() {
    //TODO
}