/*
 * Line.cpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Geometry/Segment.hpp"

#include <memory>

namespace Geometry {

	template<class T>
	Segment<T>::Segment(T start_x, T start_y, T end_x, T end_y): start(std::move(start_x), std::move(start_y)), end(std::move(end_x), std::move(end_y)) {}

	template<class T>
	Segment<T>::Segment(Point _start, Point _end): start(std::move(_start)), end(std::move(_end)) {}

	template<class T>
	Segment<T>::Segment(const Point& _start, const Point& _end) : start(_start), end(_end) {}

	template<class T>
	bool Segment<T>::intersects(const Segment<T>& other) const {
		return false;
	}

	template<class T>
	Segment<T>::~Segment() {}
}

