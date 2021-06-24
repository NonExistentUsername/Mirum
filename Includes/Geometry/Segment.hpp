/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */
#pragma once

#include "Vector2.hpp"
#include "../General/GlobalVariables.hpp"
#include "line_intersection.hpp"
#include "enums.hpp"
#include <math.h>

namespace Geometry {
	template<class T> class Line;
	template<class T> class Ray;

	template<class T>
	struct Segment {
		using Point = Vector2<T>;

		Point start, end;

		Segment(T start_x, T start_y, T end_x, T end_y): start(std::move(start_x), std::move(start_y)), end(std::move(end_x), std::move(end_y)) {}
		Segment(Point _start, Point _end): start(std::move(_start)), end(std::move(_end)) {}

		bool contains(const Point& point) const {
			return Ray<T>(*this).contains(point)
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

		lines_intersection<T> get_intersection(const Segment<T>& other) const {
			lines_intersection<T> intersection = Line<T>(*this).get_intersection(Line<T>(other));
			if(intersection.answer == INTERSECT_TYPES::POINT) {
				if(!(contains(intersection.point) && other.contains(intersection.point))) {
					intersection.answer = INTERSECT_TYPES::NONE;
				}
			}
			return intersection;
		}

		~Segment() {}
	};

	using Segmentf = Segment<float>;
	using Segmentd = Segment<double>;
	using Segmenti = Segment<int>;
}
