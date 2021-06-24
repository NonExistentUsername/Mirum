/*
 * Player.cpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Game/Player.hpp"
#include "../Includes/General/EventManager.hpp"
#include "../Includes/General/Settings/Game.hpp"
#include "../Includes/UI/Functions/Scale.hpp"

namespace Game {
//		static std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//
//		auto duration = std::chrono::steady_clock::now() - start;
//
//
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//			position.x -= Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.;
//		}
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//			position.x += Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.;
//		}
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//			position.y -= Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.;
//		}
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//			position.y += Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.;
//		}
//
//		start = std::chrono::steady_clock::now();

	Player::Player(): position(1920/2, 1080/2) {
//		EventManager::frameEvent += MY_METHOD_HANDLER(Player::processMove);
	}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {

		sf::CircleShape image;

		float _scaledSize = ScaleSize(30);
		Point _scaledPos = Scale(position);
		_scaledPos.x -= _scaledSize;
		_scaledPos.y -= _scaledSize;

		image.setPosition(_scaledPos.x, _scaledPos.y);
		image.setFillColor(sf::Color::Black);
		image.setRadius(ScaleSize(30));

		target.draw(image);
	}

	void Player::move(Geometry::Vector2<double> vector) {
		position += vector;
	}

	void Player::moveX(double value) {
		position.x += value;
	}

	void Player::moveY(double value) {
		position.y += value;
	}

	Player::~Player() {
//		EventManager::frameEvent -= MY_METHOD_HANDLER(Player::processMove);
	}
}
