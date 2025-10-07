#pragma once
#include <cmath>

struct Vector2D {
    float x, y;

    Vector2D() = default;

    Vector2D(float a, float b) {
        x = a;
        y = b;
    }

    float &operator [](int i) {
        return (&x)[i];
    }

    const float &operator [](int i) const {
        return (&x)[i];
    }

    Vector2D &operator *=(float s) {
        x *= s;
        y *= s;

        return *this;
    }

    Vector2D &operator /=(float s) {
        s = 1.0F / s;

        x *= s;
        y *= s;

        return *this;
    }

    Vector2D &operator +=(const Vector2D &v) {
        x += v.x;
        y += v.y;

        return *this;
    }

    Vector2D &operator -=(const Vector2D &v) {
        x -= v.x;
        y -= v.y;

        return *this;
    }
};

inline Vector2D operator *(const Vector2D &v, float s) {
    return {v.x * s, v.y * s};
}

inline Vector2D operator /(const Vector2D &v, float s) {
    s = 1.0F / s;

    return {v.x * s, v.y * s};
}

inline Vector2D operator -(const Vector2D &v) {
    return {-v.x, -v.y};
}

inline Vector2D operator +(const Vector2D &a, const Vector2D &b) {
    return {a.x + b.x, a.y + b.y};
}

inline Vector2D operator -(const Vector2D &a, const Vector2D &b) {
    return {a.x - b.x, a.y - b.y};
}

inline float Magnitude(const Vector2D &v) {
    return (sqrt(v.x * v.x + v.y * v.y));
}

inline Vector2D Normalize(const Vector2D &v) {
    const float mag = std::sqrt(v.x * v.x + v.y * v.y);

    return v * (1.0f / mag);
}