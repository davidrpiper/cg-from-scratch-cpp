//
// Created by David Piper on 9/4/2024.
//

#ifndef CG_FROM_SCRATCH_CPP_TGACOLOR_H
#define CG_FROM_SCRATCH_CPP_TGACOLOR_H

#include <cstdint>

struct TGAColor {
    static TGAColor rgba(unsigned char R, unsigned char G, unsigned char B, unsigned char A);
    static TGAColor rgb(unsigned char R, unsigned char G, unsigned char B);

    std::uint8_t bgra[4] = {0,0,0,0};
    std::uint8_t bytespp = 4;
    std::uint8_t& operator[](const int i) { return bgra[i]; }
};

#endif //CG_FROM_SCRATCH_CPP_TGACOLOR_H
