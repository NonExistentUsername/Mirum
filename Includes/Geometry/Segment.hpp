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

		Segment(T start_x, T start_y, T end_x, T end_y);
		Segment(Point start, Point end);
		Segment(const Point& start, const Point& end);

		bool intersects(const Segment<T>& other) const;

		~Segment();
	};
}
