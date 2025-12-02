#pragma once
#include <cmath>

struct Vec3 {
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

    // Addition
    Vec3 operator+(const Vec3& v) const {
        return {x + v.x, y + v.y, z + v.z};
    }

    // Subtraction
    Vec3 operator-(const Vec3& v) const {
        return {x - v.x, y - v.y, z - v.z};
    }

    // Scalar product
    Vec3 operator*(float f) const {
        return {x*f, y*f, z*f};
    }

    // Dot product
    [[nodiscard]] float dot (const Vec3& v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    // Cross product
    [[nodiscard]] Vec3 cross(const Vec3& v) const {
        float i = y*v.z - z*v.y;
        float j = -(x*v.z - z*v.x);
        float k = (x*v.y - y*v.x);
        return {i, j, k};
    }

    // Magnitude of vector
    [[nodiscard]] float length() const {
        return sqrtf(x*x + y*y + z*z);
    }

    // Unit vector
    [[nodiscard]] Vec3 normalize() const {
        const float l = length();
        return (l == 0) ? Vec3() : Vec3(x / l, y / l, z / l);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}