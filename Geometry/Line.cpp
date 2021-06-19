/*
 * Line.cpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Geometry/Line.hpp"

#include <memory>

namespace Geometry {
	template<class T>
	Line<T>::Line(T _k, T _b): k(_k), b(_b) {}

	template<class T>
	Line<T>::Line(T&& _k, T&& _b): k(std::move(_k)), b(std::move(_b)) {}

	template<class T>
	LINE_INTERSECT_TYPES Line<T>::intersects(const Line<T>& other) const {

	}

	template<class T>
	Line<T>::lines_intersection Line<T>::get_intersection(const Line<T>& other) const {

	}

	template<class T>
	Line<T>::~Line() {}
}
