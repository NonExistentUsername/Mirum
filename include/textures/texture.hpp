#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "itexture.hpp"

class Texture : public ITexture {
private:
    using _weak_renderer_ptr = IRenderer*;
    
    std::shared_ptr<sf::Texture> texture;
public:
    Texture(std::shared_ptr<sf::Texture> texture);

    void draw(_weak_renderer_ptr renderer) override;
};