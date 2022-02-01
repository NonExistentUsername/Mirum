#pragma once

template<class T>
class Rect {
public:
    T x, y;
    T height, width;

    Rect() {}
    Rect(T x, T y, T width, T height):
        x(x), y(y), width(width), height(height) {}
};