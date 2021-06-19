/*
 * Player.hpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Map.hpp"

#include <string>
#include <iostream>
#include <chrono>

namespace Game {
	class Player : public sf::Drawable {
	private:
		sf::Vector2f position;

		std::chrono::steady_clock start;

		void processMove();
	public:
		Player();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~Player();
	};
}
