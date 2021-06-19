/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "Point.hpp"
#include <stdint.h>

namespace Geometry {
	enum LINE_INTERSECT_TYPES {
		PARALLEL,
		POINT,
		INFINITUDE,
	};

	template<class T>
	struct Line {
		// y = k * x + b
		T k, b;

		struct lines_intersection {
			LINE_INTERSECT_TYPES answer;
			Point<T> point;
		};

		Line(T k, T b);
		Line(T&& k, T&& b);

		LINE_INTERSECT_TYPES intersects(const Line<T>& other) const;
		lines_intersection get_intersection(const Line<T>& other) const;

		~Line();
	};
}
