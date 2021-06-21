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
//#include "GameProcessor.hpp"
#include "../Geometry/Line.hpp"
#include "../Geometry/Segment.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace Geometry;

namespace Game {
	class Map : public sf::Drawable {
	protected:
		std::vector<sf::Vector2f> points;

		std::vector<Line<float>> lines;

		friend class Processor;
	public:
		Map() {
			points.push_back({0, 0});
			points.push_back({1920, 0});
			points.push_back({0, 1080});
			points.push_back({1920, 1080});


			lines.push_back(Segmentf(0, 0, 1920, 0));
			lines.push_back(Segmentf(1920, 0, 1920, 1080));
			lines.push_back(Segmentf(1920, 1080, 0, 1080));
			lines.push_back(Segmentf(0, 1080, 0, 0));
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			for(const sf::Vector2f& pos : points) {
				drawPoint(target, states, Scale(pos), ScaleSize(20), sf::Color::Red);
			}
		}
	};
}
