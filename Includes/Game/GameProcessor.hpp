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

#include <string>
#include <iostream>

namespace Game {
	class Processor : public sf::Drawable {
	private:
		Player user;

		Map map;

		void drawLines(sf::RenderTarget& target, sf::RenderStates states) const {
			for(const auto& point : map.points)
				drawLine(target, states, Scale(user.position), Scale(point), sf::Color::Blue);
		}

		void updateRay(Segmentf& ray, const Segmentf& segment) const {
			auto intersection = ray.get_intersection(segment);

			if(intersection.answer == INTERSECT_TYPES::POINT) {
				ray.end = intersection.point;
//				std::cerr << "intersect!" << std::endl;
			}
//				std::cerr << "no intersect!" << std::endl;


//			std::cerr << "answer = " << (int)intersection.answer << std::endl;
		}

		void updateRay(Segmentf& ray) const {
//			std::cout << "size of segments " << map.segments.size() << std::endl;
			for(const auto& segment : map.segments)
				updateRay(ray, segment);
//			updateRay(ray, map.segments[2]);
		}

		void drawRays(sf::RenderTarget& target, sf::RenderStates states) const {
			sf::Vector2f _mouse_position = UnScale(sf::Vector2f(sf::Mouse::getPosition(window)));

			Segmentf ray(user.position.x, user.position.y, _mouse_position.x, _mouse_position.y);

			float _new_size = 2300;
			float _k = _new_size / ray.get_size();
			ray.end.x = _k * (ray.end.x - ray.start.x) + ray.start.x;
			ray.end.y = _k * (ray.end.y - ray.start.y) + ray.start.y;

			updateRay(ray);

			drawLine(target, states, Scale(sf::Vector2f(ray.start.x, ray.start.y)),
									 Scale(sf::Vector2f(ray.end.x, ray.end.y)), sf::Color::Green);
		}
	public:
		Processor() {

		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
			target.draw(user, states);
			target.draw(map, states);

//			drawLines(target, states);
			drawRays(target, states);
		}
	};
}
