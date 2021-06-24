/*
 * line_intersection.hpp
 *
 *  Created on: 23 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "Vector2.hpp"
#include "enums.hpp"

namespace Geometry {
	template<class T>
	struct lines_intersection {
		INTERSECT_TYPES answer;
		Vector2<T> point;
	};
}
