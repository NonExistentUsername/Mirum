/*
 * Map.hpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/Functions/Scale.hpp"
#include "../UI/Functions/Drawing.hpp"

#include <string>
#include <iostream>
#include <vector>

namespace Game {
	class Map : public sf::Drawable {
	protected:
		std::vector<sf::Vector2f> points;

		friend class Processor;
	public:
		Map() {
			points.push_back({0, 0});
			points.push_back({1920, 0});
			points.push_back({0, 1080});
			points.push_back({1920, 1080});
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			for(const sf::Vector2f& pos : points) {
				drawPoint(target, states, Scale(pos), ScaleSize(20), sf::Color::Red);
			}
			#ifdef DEBUG
			//
			#endif
		}
	};
}
