/*
 * Point.cpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Geometry/Vector2.hpp"

#include <memory>

namespace Geometry {
	template<class T>
	Vector2<T>::Vector2(T _x, T _y): x(_x), y(_y) {}

	template<class T>
	Vector2<T>::Vector2(T&& _x, T&& _y): x(std::move(_x)), y(std::move(_y)) {}

	template<class T>
	Vector2<T>::Vector2(const Vector2<T>& other): x(other.x), y(other.y) {}

	template<class T>
	Vector2<T>::Vector2(Vector2<T>&& other): x(std::move(other.x)), y(std::move(other.y)) {}

	template<class T>
	Vector2<T>& Vector2<T>::operator=(Vector2<T>&& other) {
		x = std::move(other.x);
		y = std::move(other.y);
		return *this;
	}

//-------------------------------------------------------------------------

	template<class T>
	Vector2<T> Vector2<T>::operator+(T val) {
		return Vector2<T>(x + val, y + val);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator-(T val) {
		return Vector2<T>(x - val, y - val);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator*(T val) {
		return Vector2<T>(x * val, y * val);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator/(T val) {
		return Vector2<T>(x / val, y / val);
	}

//-------------------------------------------------------------------------

	template<class T>
	Vector2<T>& Vector2<T>::operator+=(T val) {
		x += val;
		y += val;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator-=(T val) {
		x -= val;
		y -= val;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator*=(T val) {
		x *= val;
		y *= val;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator/=(T val) {
		x /= val;
		y /= val;
		return *this;
	}

//-------------------------------------------------------------------------

	template<class T>
	Vector2<T> Vector2<T>::operator+(Vector2<T> val) {
		return Vector2<T>(x + val.x, y + val.y);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator-(Vector2<T> val) {
		return Vector2<T>(x - val.x, y - val.y);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator*(Vector2<T> val) {
		return Vector2<T>(x * val.x, y * val.y);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator/(Vector2<T> val) {
		return Vector2<T>(x / val.x, y / val.y);
	}

//-------------------------------------------------------------------------

	template<class T>
	Vector2<T>& Vector2<T>::operator+=(Vector2<T> val) {
		x += val.x;
		y += val.y;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator-=(Vector2<T> val) {
		x -= val.x;
		y -= val.y;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator*=(Vector2<T> val) {
		x *= val.x;
		y *= val.y;
		return *this;
	}

	template<class T>
	Vector2<T>& Vector2<T>::operator/=(Vector2<T> val) {
		x /= val.x;
		y /= val.y;
		return *this;
	}

//-------------------------------------------------------------------------

	template<class T>
	Vector2<T>::~Vector2() {}
}
