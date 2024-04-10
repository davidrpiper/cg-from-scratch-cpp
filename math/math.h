//
// Created by David Piper on 10/4/2024.
// We're being "super fucking lazy" with types.
// It's just a textbook walkthrough, and I need to find my old cstdint math types,
// as well as get to know proper Accelerate / SIMD types.
//

#ifndef CG_FROM_SCRATCH_CPP_MATH_H
#define CG_FROM_SCRATCH_CPP_MATH_H

struct Vec2 {
    int x = 0;
    int y = 0;
};

struct uVec2 {
    unsigned int x = 0;
    unsigned int y = 0;
};

// The Dark Urge
// struct Vec2 {
//     union { int x = 0, w; };
//     union { int y = 0, h; };
// };

struct Vec3 {
    int x = 0;
    int y = 0;
    int z = 0;
};

struct Vec4 {
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;
};

#endif //CG_FROM_SCRATCH_CPP_MATH_H
