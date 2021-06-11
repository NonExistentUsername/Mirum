/*
 * drawImage.cpp
 *
 *  Created on: 11 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Functions/Drawing.hpp"
#include "../../Includes/UI/Functions/Scale.hpp"

#include "../../Includes/General/Settings.hpp"

#include <string>

void drawImage(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::shared_ptr<sf::Texture> texture) {
	if(texture.get()) {
		sf::Sprite _sprite;

		_sprite.setPosition(_scaledCanvas.left, _scaledCanvas.top);
		_sprite.setTexture(*(texture.get()));

		_sprite.setScale(sf::Vector2f(_scaledCanvas.width / (float)texture.get()->getSize().x,
									 _scaledCanvas.height / (float)texture.get()->getSize().y));

		target.draw(_sprite, states);
	}
}

void drawText(sf::RenderTarget& target, sf::RenderStates states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color) {
	if(!text.empty()) {
		sf::Text _text;
		_text.setFont(Settings::textFont);
		_text.setCharacterSize(ScaleSize(Settings::fontSize));
		_text.setString(text);
		_text.setFillColor(_color);

		sf::Vector2f _canvasCenter = Center(_scaledCanvas);
		_text.setPosition(sf::Vector2f(
				_canvasCenter.x - _text.getLocalBounds().width / 2.,
				_canvasCenter.y - ScaleSize(Settings::fontSize) / 2.));

		target.draw(_text, states);
	}
}
