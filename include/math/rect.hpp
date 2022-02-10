#pragma once

#include "vec.hpp"

template<class T>
class Rect {
public:
    T x, y;
    T height, width;

    Rect() {}
    Rect(T x, T y, T width, T height):
        x(x), y(y), width(width), height(height) {}
    
    template<class V>
    bool contains(const Vec<V>& coords) const {
        return x <= coords.x && coords.x <= x + width && y <= coords.y && coords.y <= y + height;
    }
};