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
#include "../Geometry/Ray.hpp"
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

		inline void processMove();
		inline void load_map();

		inline Vector2d get_ray_intersection(const Rayd& ray) const;

		friend class Processor;
	public:
		Map();

		std::vector<Vector2<double>> get_light_points(const Vector2d& light_source) const;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~Map();
	};
}
