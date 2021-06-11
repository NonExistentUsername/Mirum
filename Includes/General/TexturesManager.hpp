/*
 * Textures.hpp
 *
 *  Created on: 1 апр. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class TexturesManager {
private:
public:
	static const std::shared_ptr<sf::Texture> Button;
	static const std::shared_ptr<sf::Texture> ButtonPressed;
};
