#include "TGAColor.h"

TGAColor TGAColor::rgba(unsigned char R, unsigned char G, unsigned char B, unsigned char A) {
    TGAColor color = { B, G, R, A, 4};
    return color;
}

TGAColor TGAColor::rgb(unsigned char R, unsigned char G, unsigned char B) {
    TGAColor color = { B, G, R, 255, 3};
    return color;
}
