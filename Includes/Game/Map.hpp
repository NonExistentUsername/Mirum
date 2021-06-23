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
#include "Player.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace Geometry;

namespace Game {
	class Map : public sf::Drawable {
	protected:
		std::unique_ptr<Player> user;

		std::vector<Segmentd> segments;

		void processMove();

		friend class Processor;
	public:
		Map() : user(new Player()) {
			EventManager::frameEvent += MY_METHOD_HANDLER(Map::processMove);

			segments.push_back(Segmentd(0, 0, 1920, 0)); //0
			segments.push_back(Segmentd(1920, 0, 1920, 1080));
			segments.push_back(Segmentd(1920, 1080, 0, 1080)); // 2
			segments.push_back(Segmentd(0, 1080, 0, 0)); //3
			segments.push_back(Segmentd{100, 100, 150, 300}); //4
			segments.push_back(Segmentd{300, 100, 200, 800}); //5
			segments.push_back(Segmentd{900, 900, 700, 1000}); //6
			segments.push_back(Segmentd{500, 500, 900, 500}); //7
			segments.push_back(Segmentd{500, 500, 500, 900}); //8
			segments.push_back(Segmentd{900, 900, 500, 900}); //9
			segments.push_back(Segmentd{900, 900, 900, 500}); //10
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			target.draw(*(user.get()), states);

			for(const Segmentd& segment : segments) {
				drawLine(target, states, Scale(sf::Vector2f(segment.start.x, segment.start.y)),
										 Scale(sf::Vector2f(segment.end.x, segment.end.y)), sf::Color::Magenta);
			}
		}

		~Map() {
			EventManager::frameEvent += MY_METHOD_HANDLER(Map::processMove);
		}
	};
}
