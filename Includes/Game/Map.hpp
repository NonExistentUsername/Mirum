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

		std::vector<Segmentf> segments;

		friend class Processor;
	public:
		Map() {
			points.push_back({0, 0});
			points.push_back({1920, 0});
			points.push_back({0, 1080});
			points.push_back({1920, 1080});


			segments.push_back(Segmentf(0, 0, 1920, 0)); //0
			segments.push_back(Segmentf(1920, 0, 1920, 1080));
			segments.push_back(Segmentf(1920, 1080, 0, 1080)); // 2
			segments.push_back(Segmentf(0, 1080, 0, 0)); //3
			segments.push_back(Segmentf{100, 100, 150, 300}); //4
			segments.push_back(Segmentf{300, 100, 200, 800}); //5
			segments.push_back(Segmentf{900, 900, 700, 1000});
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			for(const sf::Vector2f& pos : points) {
				drawPoint(target, states, Scale(pos), ScaleSize(20), sf::Color::Red);
			}

			for(const Segment<float>& segment : segments) {
				drawLine(target, states, Scale(sf::Vector2f(segment.start.x, segment.start.y)),
										 Scale(sf::Vector2f(segment.end.x, segment.end.y)), sf::Color::Magenta);
			}
		}
	};
}
