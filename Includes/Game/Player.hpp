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

namespace Game {
	class Player : public sf::Drawable {
	private:
		sf::Vector2f position;

		void processMove();
	public:
		Player();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~Player();
	};
}
