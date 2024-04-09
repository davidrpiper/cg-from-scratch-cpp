//
// Created by David Piper on 9/4/2024.
//

#ifndef CG_FROM_SCRATCH_CPP_CANVAS_H
#define CG_FROM_SCRATCH_CPP_CANVAS_H

#include <string>
#include "TGA/TGAColor.h"
#include "TGA/TGAImage.h"

class Canvas {
public:
    Canvas();
    Canvas(unsigned int width, unsigned int height);
    ~Canvas();

    void putPixel(const unsigned int x, const unsigned int y, const TGAColor& color);
    void saveImage(const std::string &filename);
    void saveImage(const char *filename);
private:
    TGAImage image;
};


#endif //CG_FROM_SCRATCH_CPP_CANVAS_H
