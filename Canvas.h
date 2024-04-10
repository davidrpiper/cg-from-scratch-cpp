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

    unsigned int width() const;
    unsigned int height() const;

     /**
      * The Canvas co-ordinate system is Cartesian: (x, y) = (0, 0) is the horizontal and vertical center of the canvas.
      *
      * @param x coordinates left-of-center will be negative, right-of-center will be positive
      * @param y coordinates below-center will be negative, above-center will be positive
      * @param color to paint the pixel at the given Canvas coordinates
      */
    void putPixel(const int x, const int y, const TGAColor& color);

    /**
     * Save the image to a file in the current working directory
     */
    void saveImage(const std::string &filename) const;
    void saveImage(const char *filename) const;

private:
    TGAImage image;
};


#endif //CG_FROM_SCRATCH_CPP_CANVAS_H
