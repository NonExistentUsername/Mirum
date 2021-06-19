/*
 * GameProcessor.hpp
 *
 *  Created on: 15 θών. 2021 γ.
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

		Map map;

	public:
		Processor() {

		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			target.draw(user, states);
			target.draw(map, states);

//			drawLines(target, states);
		}
	};
}
