/*
 * Player.cpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Game/Player.hpp"
#include "../Includes/General/EventManager.hpp"
#include "../Includes/UI/Functions/Scale.hpp"

namespace Game {
	void Player::processMove() {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			position.x--;
		} else
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			position.x++;
		} else
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			position.y++;
		} else
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			position.y--;
		}
	}

	Player::Player(): position(1920/2, 1080/2) {
		EventManager::frameEvent += MY_METHOD_HANDLER(Player::processMove);
	}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {

		sf::CircleShape image;
		image.setPosition(Scale(position));
		image.setFillColor(sf::Color::Black);
		image.setRadius(ScaleSize(30));

		target.draw(image);
	}

	Player::~Player() {
		EventManager::frameEvent -= MY_METHOD_HANDLER(Player::processMove);
	}
}
