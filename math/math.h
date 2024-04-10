//
// Created by David Piper on 10/4/2024.
// We're being "super fucking lazy" with types.
// It's just a textbook walkthrough, and I need to find my old cstdint math types,
// as well as get to know proper Accelerate / SIMD types. And actual good encapsulation.
//

#ifndef CG_FROM_SCRATCH_CPP_MATH_H
#define CG_FROM_SCRATCH_CPP_MATH_H

struct Vec2 {
    int x = 0;
    int y = 0;

    int dot(const Vec2 &other) {
        return this->x * other.x + this->y * other.y;
    }
};

struct Vec3 {
    int x = 0;
    int y = 0;
    int z = 0;

    int dot(const Vec3 &other) {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }
};

struct Vec3f {
    float x = 0;
    float y = 0;
    float z = 0;

    float dot(const Vec3f &other) {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }
};

struct Vec4 {
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;

    int dot(const Vec4 &other) {
        return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
    }
};

#endif //CG_FROM_SCRATCH_CPP_MATH_H
