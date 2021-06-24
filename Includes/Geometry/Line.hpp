/*
 * Line.hpp
 *
 *  Created on: 19 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include "Vector2.hpp"
#include "Segment.hpp"
#include "line_intersection.hpp"
#include <stdint.h>

namespace Geometry {
//	enum LINE_INTERSECT_TYPES {
//		PARALLEL,
//		POINT,
//		INFINITUDE,
//	};

	template<class T>
	struct Line {
//		y = k * x + b
		using Point = Vector2<T>;

		T k, b;

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
		Line(const Segment<T>& segment) {
			if(std::abs(segment.end.x - segment.start.x) <= EPS)
				k = 1e7;
			else
				k = (segment.end.y - segment.start.y) / (segment.end.x - segment.start.x);
			b = segment.start.y - k * segment.start.x;
		}

		Line(const Point& start, const Point& end) {
			k = (end.y - start.y) / (end.x - start.x);
			b = start.y - k * start.x;
		}

		Line(T start_x, T start_y, T end_x, T end_y) {
			k = (end_y - start_y) / (end_x - start_x);
			b = start_y - k * start_x;
		}

//		bool contains(const Point<T>& point) const;
		bool contains(const Point& point) const {
			return std::abs(point.x * k + b - point.y) <= EPS;
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
			if(std::abs(k - other.k) <= EPS && std::abs(b - other.b) > EPS)
				return false;
			return true;
		}

//		lines_intersection get_intersection(const Line<T>& other) const;
//		template<class T>
		lines_intersection<T> get_intersection(const Line<T>& other) const {
			lines_intersection<T> answer;
			if(std::abs(k - other.k) <= EPS) {
				if(std::abs(b - other.b) <= EPS) {
					answer.answer = INTERSECT_TYPES::INFINITUDE;
				} else {
					answer.answer = INTERSECT_TYPES::PARALLEL;
				}
			} else {
				answer.answer = INTERSECT_TYPES::POINT;
				answer.point.x = (other.b - b) / (k - other.k);
				answer.point.y = k * answer.point.x + b;

//				std::cout << "INTERSECT LINES" << std::endl;
			}

			return answer;
		}

		~Line() {};
	};
}
