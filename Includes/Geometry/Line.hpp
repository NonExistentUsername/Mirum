/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "Point.hpp"
#include "Segment.hpp"
#include <stdint.h>

namespace Geometry {
	enum LINE_INTERSECT_TYPES {
		PARALLEL,
		POINT,
		INFINITUDE,
	};

	template<class T>
	struct Line {
//		y = k * x + b
		T k, b;


		struct lines_intersection {
			LINE_INTERSECT_TYPES answer;
			Point<T> point;
		};

		Line(T _k, T _b): k(_k), b(_b) {}

/*
 *
 *		y1 = k * x1 + b
 *		y2 = k * x2 + b
 *		y2 - y1 = k * x2 - k * x1
 *		y2 - y1 = k * (x2 - x1)
 *		k = (y2 - y1) / (x2 - x1)
 *		b = y1 - k * x1
 */
		Line(Segment<T> segment) {
			k = (segment.end.y - segment.start.y) / (segment.end.x - segment.start.x);
			b = segment.start.y - k * segment.start.x;
		}

		Line(Point<T> start, Point<T> end) {
			k = (end.y - start.y) / (end.x - start.x);
			b = start.y - k * start.x;
		}

		Line(T start_x, T start_y, T end_x, T end_y) {
			k = (end_y - start_y) / (end_x - start_x);
			b = start_y - k * start_x;
		}

//		bool contains(const Point<T>& point) const;
		bool contains(const Point<T>& point) const {
			return point.x * k + b == point.y;
		}

/*
 *  	y = k1 * x + b1;
 *  	y = k2 * x + b2;
 *		0 = x * (k1 - k2) + b1 - b2;
 *		b2 - b1 = x * (k1 - k2)
 *		x = (b2 - b1) / (k1 - k2) <<
 */

//		bool intersects(const Line<T>& other) const;
		bool intersects(const Line<T>& other) const {
			if(k == other.k && b != other.b)
				return false;
			return true;
		}

//		lines_intersection get_intersection(const Line<T>& other) const;
//		template<class T>
		lines_intersection get_intersection(const Line<T>& other) const {
			lines_intersection answer;
			if(k == other.k) {
				if(b == other.b) {
					answer.answer = LINE_INTERSECT_TYPES::INFINITUDE;
				} else {
					answer.answer = LINE_INTERSECT_TYPES::PARALLEL;
				}
			}
			answer.answer = LINE_INTERSECT_TYPES::POINT;
			answer.point = (other.b - b) / (k - other.k);

			return answer;
		}

		~Line() {};
	};
}
