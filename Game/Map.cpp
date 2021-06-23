/*
 * Map.cpp
 *
 *  Created on: 23 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Game/Map.hpp"
#include "../Includes/General/Settings/Game.hpp"

namespace Game {
	void Map::processMove() {
		static std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

		auto duration = std::chrono::steady_clock::now() - start;


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			user.get()->moveX(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			user.get()->moveX(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			user.get()->moveY(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			user.get()->moveY(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}

		start = std::chrono::steady_clock::now();
	}
}
