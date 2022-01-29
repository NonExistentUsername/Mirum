#include "textures/simple_texture_loader.hpp"
#include <SFML/Graphics.hpp>

SimpleTextureLoader::SimpleTextureLoader(std::string path):
    path(std::move(path)) {}
    
std::shared_ptr<sf::Texture> SimpleTextureLoader::load() {
    sf::Texture* new_texture = new sf::Texture();
    if(!new_texture->loadFromFile(path))
        exit(EXIT_FAILURE);
    return std::shared_ptr<sf::Texture>(new_texture);
}