/*
 * Point.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <memory>

namespace Geometry {

	template<class T>
	struct Vector2 {
		T x, y;

		Vector2(T _x, T _y): x(std::move(_x)), y(std::move(_y)) {}
//		Vector2(T&& _x, T&& _y): x(std::move(_x)), y(std::move(_y)) {}
		Vector2(const Vector2<T>& other): x(other.x), y(other.y) {}

		Vector2<T>& operator=(Vector2<T>&& other) {
			x = std::move(other.x);
			y = std::move(other.y);
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T> operator+(T val) {
			return Vector2<T>(x + val, y + val);
		}

		Vector2<T> operator-(T val) {
			return Vector2<T>(x - val, y - val);
		}

		Vector2<T> operator*(T val) {
			return Vector2<T>(x * val, y * val);
		}

		Vector2<T> operator/(T val) {
			return Vector2<T>(x / val, y / val);
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T>& operator+=(T val) {
			x += val;
			y += val;
			return *this;
		}

		Vector2<T>& operator-=(T val) {
			x -= val;
			y -= val;
			return *this;
		}

		Vector2<T>& operator*=(T val) {
			x *= val;
			y *= val;
			return *this;
		}

		Vector2<T>& operator/=(T val) {
			x /= val;
			y /= val;
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T> operator+(Vector2<T> val) {
			return Vector2<T>(x + val.x, y + val.y);
		}

		Vector2<T> operator-(Vector2<T> val) {
			return Vector2<T>(x - val.x, y - val.y);
		}

		Vector2<T> operator*(Vector2<T> val) {
			return Vector2<T>(x * val.x, y * val.y);
		}

		Vector2<T> operator/(Vector2<T> val) {
			return Vector2<T>(x / val.x, y / val.y);
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T>& operator+=(Vector2<T> val) {
			x += val.x;
			y += val.y;
			return *this;
		}

		Vector2<T>& operator-=(Vector2<T> val) {
			x -= val.x;
			y -= val.y;
			return *this;
		}

		Vector2<T>& operator*=(Vector2<T> val) {
			x *= val.x;
			y *= val.y;
			return *this;
		}

		Vector2<T>& operator/=(Vector2<T> val) {
			x /= val.x;
			y /= val.y;
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		~Vector2() {}
	};

}
