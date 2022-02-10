#pragma once

#include <SFML/Graphics.hpp>

template<class T>
class Vec {
public:
    T x, y;

    Vec() {}
    Vec(const Vec<T>& vec):
        x(x), y(y) {}
    Vec(T x, T y):
        x(std::move(x)), y(std::move(y)) {}
    Vec(sf::Vector2<T> vec):
        x(std::move(x)), y(std::move(y)) {} 
};