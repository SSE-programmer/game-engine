#pragma once
#include "Vector3D.h"


struct Matrix3D {
private:
    float n[3][3];

public:
    Matrix3D() = default;

    Matrix3D(
        float n00, float n01, float n02,
        float n10, float n11, float n12,
        float n20, float n21, float n22
    ) {
        n[0][0] = n00;
        n[0][1] = n01;
        n[0][2] = n02;
        n[1][0] = n10;
        n[1][1] = n11;
        n[1][2] = n12;
        n[2][0] = n20;
        n[2][1] = n21;
        n[2][2] = n22;
    }

    Matrix3D(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
        n[0][0] = a.x;
        n[0][1] = a.y;
        n[0][2] = a.z;
        n[1][0] = b.x;
        n[1][1] = b.y;
        n[1][2] = b.z;
        n[2][0] = c.x;
        n[2][1] = c.y;
        n[2][2] = c.z;
    }

    float &operator()(int row, int col) {
        return n[col][row];
    }

    const float &operator()(int row, int col) const {
        return n[col][row];
    }

    Vector3D &operator [](int col) {
        return (*reinterpret_cast<Vector3D *>(n[col]));
    }

    const Vector3D &operator [](int col) const {
        return (*reinterpret_cast<const Vector3D *>(n[col]));
    }

    Matrix3D &operator *=(float s) {
        n[0][0] *= s; n[0][1] *= s; n[0][2] *= s;
        n[1][0] *= s; n[1][1] *= s; n[1][2] *= s;
        n[2][0] *= s; n[2][1] *= s; n[2][2] *= s;

        return *this;
    }

    Matrix3D &operator /=(float s) {
        s = 1.0F / s;

        n[0][0] *= s; n[0][1] *= s; n[0][2] *= s;
        n[1][0] *= s; n[1][1] *= s; n[1][2] *= s;
        n[2][0] *= s; n[2][1] *= s; n[2][2] *= s;

        return *this;
    }

    Matrix3D &operator +=(const Matrix3D &M) {
        n[0][0] += M[0][0]; n[0][1] += M[0][1]; n[0][2] += M[0][2];
        n[1][0] += M[1][1]; n[1][1] += M[1][1]; n[1][2] += M[1][2];
        n[2][0] += M[2][0]; n[2][1] += M[2][1]; n[2][2] += M[2][2];

        return *this;
    }

    Matrix3D &operator -=(const Matrix3D &M) {
        n[0][0] -= M[0][0]; n[0][1] -= M[0][1]; n[0][2] -= M[0][2];
        n[1][0] -= M[1][1]; n[1][1] -= M[1][1]; n[1][2] -= M[1][2];
        n[2][0] -= M[2][0]; n[2][1] -= M[2][1]; n[2][2] -= M[2][2];

        return *this;
    }
};

inline Matrix3D operator -(const Matrix3D &M) {
    return (Matrix3D(
            -M(0, 0), -M(1, 0), -M(2, 0),
            -M(1, 0), -M(1, 1), -M(1, 2),
            -M(2, 0), -M(2, 1), -M(2, 2)
        )
    );
}

inline Matrix3D operator +(const Matrix3D &A, const Matrix3D &B) {
    return (Matrix3D(
            A(0, 0) + B(0, 0), A(0, 1) + B(0, 1), A(0, 2) + B(0, 2),
            A(1, 0) + B(1, 0), A(1, 1) + B(1, 1), A(1, 2) + B(1, 2),
            A(2, 0) + B(2, 0), A(2, 1) + B(2, 1), A(2, 2) + B(2, 2)
        )
    );
}

inline Matrix3D operator -(const Matrix3D &A, const Matrix3D &B) {
    return (Matrix3D(
            A(0, 0) + B(0, 0), A(0, 1) + B(0, 1), A(0, 2) + B(0, 2),
            A(1, 0) + B(1, 0), A(1, 1) + B(1, 1), A(1, 2) + B(1, 2),
            A(2, 0) + B(2, 0), A(2, 1) + B(2, 1), A(2, 2) + B(2, 2)
        )
    );
}

inline Matrix3D operator *(const Matrix3D &M, float s) {
    return Matrix3D(
        M(0, 0) * s, M(0, 1) * s, M(0, 2) * s,
        M(1, 0) * s, M(1, 1) * s, M(1, 2) * s,
        M(2, 0) * s, M(2, 1) * s, M(2, 2) * s
    );
}

inline Matrix3D operator /(const Matrix3D &M, float s) {
    s = 1.0F / s;

    return Matrix3D(
        M(0, 0) * s, M(0, 1) * s, M(0, 2) * s,
        M(1, 0) * s, M(1, 1) * s, M(1, 2) * s,
        M(2, 0) * s, M(2, 1) * s, M(2, 2) * s
    );
}

inline Matrix3D operator *(const Matrix3D &A, const Matrix3D &B) {
    return Matrix3D(
        A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
        A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
        A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
        A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
        A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
        A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
        A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
        A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
        A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2));
}

inline Vector3D operator *(const Matrix3D &M, const Vector3D &v) {
    return (Vector3D(
            M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
            M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
            M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z)
    );
}
