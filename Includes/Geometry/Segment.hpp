/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */
#pragma once

#include "Vector2.hpp"

namespace Geometry {

	template<class T>
	struct Segment {
		using Point = Vector2<T>;

		Point start, end;

		Segment(T start_x, T start_y, T end_x, T end_y): start(std::move(start_x), std::move(start_y)), end(std::move(end_x), std::move(end_y)) {}
		Segment(Point _start, Point _end): start(std::move(_start)), end(std::move(_end)) {}
		Segment(const Point& _start, const Point& _end) : start(_start), end(_end) {}

		bool intersects(const Segment<T>& other) const {
			return false;
		}

		~Segment() {}
	};

	using Segmentf = Segment<float>;
}
