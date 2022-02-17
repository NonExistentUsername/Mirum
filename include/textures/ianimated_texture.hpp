#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "itexture.hpp"

class IAnimatedTexture : public ITexture {
protected:
    using _shared_texture = std::shared_ptr<sf::Texture>;

    IAnimatedTexture();
    IAnimatedTexture(_shared_texture texture);
};