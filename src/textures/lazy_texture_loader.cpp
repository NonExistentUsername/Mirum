#include "textures/lazy_texture_loader.hpp"

LazyTextureLoader::LazyTextureLoader(ITextureLoader* textureLoader):
    textureLoader(textureLoader), texture(nullptr) {}

std::shared_ptr<sf::Texture> LazyTextureLoader::load() {
    if(texture == nullptr) {
        texture = textureLoader->load();
        delete textureLoader;
    }
    return texture;
}

LazyTextureLoader::~LazyTextureLoader() {
    if(textureLoader)
        delete textureLoader;
}