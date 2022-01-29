#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class ITextureLoader {
public:
    virtual std::shared_ptr<sf::Texture> load() = 0;
};