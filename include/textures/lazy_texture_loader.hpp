#pragma once

#include "simple_texture_loader.hpp"

class LazyTextureLoader : public ITextureLoader {
private:
    ITextureLoader* textureLoader = nullptr;

    std::shared_ptr<sf::Texture> texture;
public:
    LazyTextureLoader(ITextureLoader* textureLoader);

    std::shared_ptr<sf::Texture> load() override;

    ~LazyTextureLoader();
};