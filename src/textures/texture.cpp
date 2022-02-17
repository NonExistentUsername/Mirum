#include "textures/texture.hpp"

Texture::Texture(std::shared_ptr<sf::Texture> texture):
    ITexture(texture) {}
    
SpriteSaver Texture::create_sprite() {
    //TODO
}