/*
 * Player.hpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../Geometry/Vector2.hpp"

#include <string>
#include <iostream>
#include <chrono>

namespace Game {
	class Player : public sf::Drawable {
	private:
		using Point = Geometry::Vector2<float>;

//		sf::Vector2f position;
		Point position;

//		std::chrono::steady_clock start;

//		void processMove();

		friend class Processor;
	public:
		Player();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void move(Geometry::Vector2<float> vector);
		void moveX(float value);
		void moveY(float value);

		~Player();
	};
}
