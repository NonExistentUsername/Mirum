/*
 * Textures.hpp
 *
 *  Created on: 1 ���. 2021 �.
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
