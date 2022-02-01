#include "textures/texture.hpp"

Texture::Texture(std::shared_ptr<sf::Texture> texture):
    texture(texture) {}
    
void Texture::draw(_weak_renderer_ptr renderer) {
    //TODO
}