/*
 * Scale.hpp
 *
 *  Created on: 29 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/Settings.hpp"

template<class T>
inline sf::FloatRect Scale(const sf::Rect<T>& rect) {
	sf::FloatRect newRect(rect);

	newRect.left = rect.left * Settings::Kx();
	newRect.top = rect.top* Settings::Ky();

	newRect.width = rect.width * Settings::Kx();
	newRect.height = rect.height * Settings::Ky();

	return newRect;
}

template<class T>
inline sf::Vector2<T> Scale(const sf::Vector2<T>& vec) {
	return sf::Vector2<T>(vec.x * Settings::Kx(), vec.y * Settings::Ky());
}

template<class T>
inline sf::Vector2<T> UnScale(const sf::Vector2<T>& vec) {
	return sf::Vector2<T>(vec.x / Settings::Kx(), vec.y / Settings::Ky());
}


template<class T>
inline T ScaleSize(T size) {
	return size * std::min(Settings::Kx(), Settings::Ky());
}

template<class T>
inline sf::Vector2<T> Center(const sf::Rect<T>& rect) {
	return {rect.left + rect.width / 2, rect.top + rect.height / 2};
}

//template<class T>
//inline sf::Vector2<T> Left(const sf::Rect<T>& rect) {
//	return {rect.left, rect.top + rect.height / 2};
//}

template<class T>
inline sf::Vector2<T> LocalCenter(const sf::Rect<T>& rect) {
	return {rect.width / 2, rect.height / 2};
}
