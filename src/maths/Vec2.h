#pragma once
#include <math.h>


struct Vec2 {
    float x, y;
    Vec2() : x(0), y(0) {}
    Vec2(const float x, const float y) : x(x), y(y) {}

    // Addition
    Vec2 operator+(const Vec2& v) const{
        return {v.x + x, v.y + y};
    }

    // Subtraction
    Vec2 operator-(const Vec2& v) const {
        return {x - v.x, y - v.y};
    }

    // Scalar product
    Vec2 operator*(const float f) const {
        return {f*x, f*y};
    }

    // Dot product
    [[nodiscard]] float dot(const Vec2& v) const {
        return x * v.x + y * v.y;
    }

    // Magnitude of vector
    [[nodiscard]] float length() const {
        return std::sqrt(x*x + y*y);
    }

    // Unit vector
    [[nodiscard]] Vec2 normalize() const {
        const float magnitude = length();
        return (magnitude == 0) ? Vec2() : Vec2({x/magnitude, y/magnitude});
    }

    // Cross product
    [[nodiscard]] float cross(const Vec2& v) const {
        return x * v.y - y * v.x;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}