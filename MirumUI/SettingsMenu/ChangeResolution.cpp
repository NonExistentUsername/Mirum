/*
 * ChangeResolution.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/SettingsMenu.hpp"
//
//SettingsMenu::ChangeResolution::ChangeResolution() {
//	canvas.top = 200;
//	canvas.left = 800;
//
//	canvas.height = 50;
//	canvas.width = 300;
//
//	text = "change resolution";
//}
//
//void SettingsMenu::ChangeResolution::released(const sf::Event& event) {
//	if(!isOpened) {
//		if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
//			isOpened = true;
//	} else
//		isOpened = false;
//}
//
//void SettingsMenu::ChangeResolution::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//	sf::FloatRect _scaledCanvas = Scale(canvas);
////	if(texture.get()) {
////		sf::Sprite _sprite;
////
////		_sprite.setPosition(_scaledCanvas.left, _scaledCanvas.top);
////		_sprite.setTexture(*(texture.get()));
////
////		_sprite.setScale(sf::Vector2f(_scaledCanvas.width / (float)texture.get()->getSize().x,
////									 _scaledCanvas.height / (float)texture.get()->getSize().y));
////
////		target.draw(_sprite, states);
////	}
//	if(!isOpened) {
//		sf::Text _text;
//		_text.setFont(Settings::textFont);
//		_text.setCharacterSize(ScaleSize(Settings::fontSize));
//		_text.setString(text);
//		_text.setFillColor(sf::Color(0, 0, 0));
//
//		sf::Vector2f _canvasCenter = Center(_scaledCanvas);
//		_text.setPosition(sf::Vector2f(
//				_canvasCenter.x - _text.getLocalBounds().width / 2.,
//				_canvasCenter.y - ScaleSize(Settings::fontSize) / 2.));
//
//		target.draw(_text, states);
//	} else {
//
//	}
//}
//
//SettingsMenu::ChangeResolution::~ChangeResolution() {}
//
