/*
 * GameProcessor.hpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Map.hpp"
#include "../../Includes/UI/Functions/Drawing.hpp"
#include "../Geometry/Functions.hpp"
#include "../Geometry/Ray.hpp"

#include "../Tools/Profile.hpp"

#include <string>
#include <iostream>
#include <memory>

using namespace Geometry;

namespace Game {
	class Processor : public sf::Drawable {
	private:
		std::unique_ptr<Map> map;

		void drawRays(sf::RenderTarget& target, const sf::RenderStates& states) const {
			{
				sf::Vector2f _mouse_position_f = UnScale(sf::Vector2f(sf::Mouse::getPosition(window)));
				Vector2d _mouse_position(_mouse_position_f.x, _mouse_position_f.y);

				Rayd ray(map.get()->user.get()->position, _mouse_position - map.get()->user.get()->position);

//				std::cerr << "Rayd ray " << ray.direction.x << " " << ray.direction.y << std::endl;

//				Geometry::rotate(ray, ray.start, Geometry::degree_to_radian(10));
				double len = INFINITY;
				Vector2d ans = _mouse_position;
				for(const auto& segment : map.get()->segments)
				{
//				const auto& segment = map.get()->segments[1];
					auto intersection = ray.get_intersection(segment);

					if(intersection.answer == INTERSECT_TYPES::POINT && get_length(map.get()->user.get()->position, intersection.point) + EPS <= len && segment.contains(intersection.point)) {
						len = get_length(map.get()->user.get()->position, intersection.point);
						ans = intersection.point;

						drawPoint(target, states, intersection.point, 10, sf::Color::Green);
					} else
					if(intersection.answer == INTERSECT_TYPES::POINT && get_length(map.get()->user.get()->position, intersection.point) + EPS <= len && !segment.contains(intersection.point)) {
						drawPoint(target, states, intersection.point, 10, sf::Color::Cyan);

//						std::cerr << intersection.point.x << " " << intersection.point.y << std::endl;
					}
					else
					if(intersection.answer == INTERSECT_TYPES::POINT) {
						drawPoint(target, states, intersection.point, 10, sf::Color::Red);
					}
				}

				drawLine(target, states, Scale(sf::Vector2f(ray.start.x, ray.start.y)),
										 Scale(sf::Vector2f(ans.x, ans.y)), sf::Color::Blue);
			}
		}

		void drawRays2(sf::RenderTarget& target, const sf::RenderStates& states) const {
			std::vector<Vector2d> points = map.get()->get_light_points(map.get()->user.get()->position);

			sf::Vector2f _scaled_user_position(map.get()->user.get()->position.x,
											   map.get()->user.get()->position.y);
			_scaled_user_position = Scale(_scaled_user_position);

			for(const auto& point : points) {
				drawLine(target, states, _scaled_user_position,
						 Scale(sf::Vector2f(point.x, point.y)), sf::Color::Yellow);

				//////////////////////////////////////////////////////
				///
				///		drawPoint is so slow..
				///
				//////////////////////////////////////////////////////
				drawPoint(target, states, point, 10, sf::Color::Yellow);
			}
//			for(size_t i = 1; i < points.size(); ++i) {
//				drawLine(target, states,
//						Scale(sf::Vector2f(points[i - 1].x, points[i - 1].y)),
//						Scale(sf::Vector2f(points[i].x, points[i].y)), sf::Color::Yellow);
//			}
//			drawLine(target, states,
//					Scale(sf::Vector2f(points[points.size() - 1].x, points[points.size() - 1].y)),
//					Scale(sf::Vector2f(points[0].x, points[0].y)), sf::Color::Yellow);
		}
	public:
		Processor() : map(new Map()) {}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			target.draw(*(map.get()), states);


//			drawRays(target, states);
			{
				drawRays2(target, states);
			}
		}
	};
}
