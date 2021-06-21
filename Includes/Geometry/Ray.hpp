/*
 * Ray.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "Vector2.hpp"

namespace Geometry{

	template<class T>
	struct Ray {
		using Point = Vector2<T>;

		Point start;
		T direction;
//		new_point = point + len * k;
//
		Ray(Point _start, T _direction): start(_start), direction(_direction) {}


	};

}
