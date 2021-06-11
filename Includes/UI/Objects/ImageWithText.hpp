/*
 * ImageWithText.hpp
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/GlobalVariables.hpp"
#include "../../General/TexturesManager.hpp"
#include "../Functions/Scale.hpp"

#include <iostream>
#include <string>

namespace UI {
	class ImageWithText : public sf::Drawable {
	private:
		sf::IntRect canvas;
		std::shared_ptr<sf::Texture> texture;
		std::string text;
		sf::Color textColor;
	public:
		ImageWithText();

	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		~ImageWithText();
	};
}
