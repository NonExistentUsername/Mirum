#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SpriteSaver {
public:
    sf::Sprite& get() const;
};

class SpritePool {
private:
    int next_id;
    std::vector<sf::Sprite> sprites;

    void clear(sf::Sprite& sprite);
public:
    SpriteSaver create();
};