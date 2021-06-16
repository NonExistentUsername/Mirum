/*
 * GameProcessor.hpp
 *
 *  Created on: 15 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"

#include <string>
#include <iostream>

namespace Game {
	class Processor : public sf::Drawable {
	private:
		Player user;
	public:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			target.draw(user, states);
		}
	};
}
