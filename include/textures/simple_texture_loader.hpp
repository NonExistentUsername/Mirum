#pragma once

#include <string>
#include "itexture_loader.hpp"

class SimpleTextureLoader : public ITextureLoader {
private:
    std::string path;
public:
    SimpleTextureLoader(std::string path);
    
    std::shared_ptr<sf::Texture> load() override;
};