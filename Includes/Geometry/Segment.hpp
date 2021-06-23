/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */
#pragma once

#include "Vector2.hpp"
//#include "Line.hpp"
#include "../General/GlobalVariables.hpp"
#include "enums.hpp"
#include <math.h>

namespace Geometry {
	template<class T> class Line;

	template<class T>
	struct Segment {
		using Point = Vector2<T>;

		Point start, end;

		Segment(T start_x, T start_y, T end_x, T end_y): start(std::move(start_x), std::move(start_y)), end(std::move(end_x), std::move(end_y)) {}
		Segment(Point _start, Point _end): start(std::move(_start)), end(std::move(_end)) {}
		Segment(const Point& _start, const Point& _end) : start(_start), end(_end) {}

		bool contains(const Point& point) const {

			Line<T> _t(*this);

//			if(!_t.contains(point)) {
//				std::cerr << "not contains" << std::endl;
//				std::cerr << point.x << " " << point.y << std::endl;
//				std::cerr << "k,b " << _t.k << " " << _t.b << std::endl;
//			}
//			if(!(	   std::min(start.x, end.x) - EPS <= point.x
//					&& std::min(start.y, end.y) - EPS <= point.y
//					&& point.x <= std::max(start.x, end.x) + EPS
//					&& point.y <= std::max(start.y, end.y) + EPS)) {
//				std::cerr << "not contains XZX" << std::endl;
//				std::cerr << point.x << " " << point.y << std::endl;
//				std::cerr << "X }{ " << std::min(start.x, end.x) - EPS << " " << std::max(start.x, end.x) + EPS << std::endl;
//				std::cerr << "Y }{ " << std::min(start.y, end.y) - EPS << " " << std::max(start.y, end.y) + EPS << std::endl;
//
//			}
//
			return Line<T>(*this).contains(point)
					&& (std::min(start.x, end.x) - EPS <= point.x
					&& std::min(start.y, end.y) - EPS <= point.y
					&& point.x <= std::max(start.x, end.x) + EPS
					&& point.y <= std::max(start.y, end.y) + EPS);
		}

		float get_size() const {
			return std::sqrt((end.x - start.x) * (end.x - start.x)
					+ (end.y - start.y) * (end.y - start.y));
		}

		bool intersects(const Segment<T>& other) const {
			auto intersection = Line<T>(*this).get_intersection(Line<T>(other));
			if(intersection.answer == INTERSECT_TYPES::POINT) {
				return contains(intersection.point) && other.contains(intersection.point);
			}
			return false;
		}

		auto get_intersection(const Segment<T>& other) const {
			auto intersection = Line<T>(*this).get_intersection(Line<T>(other));
			if(intersection.answer == INTERSECT_TYPES::POINT) {
				if(!(contains(intersection.point) && other.contains(intersection.point))) {
					intersection.answer = INTERSECT_TYPES::NONE;
//					std::cerr << "NOT CONTAINS" << std::endl;
				}
			}
			return intersection;
		}


		~Segment() {}
	};

//	using Segmentf = Segment<float>;
	using Segmentd = Segment<double>;
}
