/*
 * Map.cpp
 *
 *  Created on: 23 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Game/Map.hpp"
#include "../Includes/Geometry/Ray.hpp"
#include "../Includes/Geometry/Functions.hpp"
#include "../Includes/General/Settings/Game.hpp"
#include "../Includes/Tools/Profile.hpp"

namespace Game {
	inline void Map::processMove() {
		static std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

		auto duration = std::chrono::steady_clock::now() - start;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			user.get()->moveX(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			user.get()->moveX(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			user.get()->moveY(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			user.get()->moveY(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}

		start = std::chrono::steady_clock::now();
	}


	inline void Map::load_map() {
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

	Map::Map() : user(new Player()) {
		EventManager::frameEvent += MY_METHOD_HANDLER(Map::processMove);

		load_map();
	}

	void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(*(user.get()), states);

		for(const Segmentd& segment : segments) {
			drawLine(target, states, Scale(sf::Vector2f(segment.start.x, segment.start.y)),
									 Scale(sf::Vector2f(segment.end.x, segment.end.y)), sf::Color::Magenta);
		}
	}

	inline Vector2d Map::get_ray_intersection(const Rayd& ray) const {
		Vector2d point(ray.start);
		double min_length = INFINITY;
		for(const auto& segment : segments) {
			auto intersection = ray.get_intersection(segment);

			double length = get_length(ray.start, intersection.point);
			if(intersection.answer == INTERSECT_TYPES::POINT && length <= min_length - EPS && segment.contains(intersection.point)) {
				min_length = length;
				point = intersection.point;
			}
		}

		return point;
	}

	std::vector<Vector2d> Map::get_light_points(const Vector2d& light_source) const {
//		LOG_DURATION("calc light_points");

		std::vector<Vector2<double>> light_points(4 * segments.size());

		size_t id = 0;
		const double angle = 0.0001;
		for(const auto& segment : segments) {
			Ray<double> new_ray(light_source, segment.start - light_source);

			new_ray.direction.rotate(degree_to_radian(angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray.direction.rotate(degree_to_radian(-2 * angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray = Ray<double>(light_source, segment.end - light_source);
			new_ray.direction.rotate(degree_to_radian(angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray.direction.rotate(degree_to_radian(-2 * angle));
			light_points[id++] = get_ray_intersection(new_ray);
		}

		return light_points;
	}

	Map::~Map() {
		EventManager::frameEvent -= MY_METHOD_HANDLER(Map::processMove);
	}
}
