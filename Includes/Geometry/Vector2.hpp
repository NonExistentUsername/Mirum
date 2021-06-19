/*
 * Point.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

namespace Geometry {

	template<class T>
	struct Vector2 {
		T x, y;

		Vector2(T x, T y);
		Vector2(T&& x, T&& y);
		Vector2(const Vector2<T>& other);

		Vector2(Vector2<T>&& other);
		Vector2<T>& operator=(Vector2<T>&& other);

		Vector2<T> operator+(T val);
		Vector2<T> operator-(T val);
		Vector2<T> operator*(T val);
		Vector2<T> operator/(T val);

		Vector2<T>& operator+=(T val);
		Vector2<T>& operator-=(T val);
		Vector2<T>& operator*=(T val);
		Vector2<T>& operator/=(T val);

		Vector2<T> operator+(Vector2<T> val);
		Vector2<T> operator-(Vector2<T> val);
		Vector2<T> operator*(Vector2<T> val);
		Vector2<T> operator/(Vector2<T> val);

		Vector2<T>& operator+=(Vector2<T> val);
		Vector2<T>& operator-=(Vector2<T> val);
		Vector2<T>& operator*=(Vector2<T> val);
		Vector2<T>& operator/=(Vector2<T> val);

		~Vector2();
	};

}
