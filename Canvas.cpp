//
// Created by David Piper on 9/4/2024.
//

#include "TGA/TGAImage.h"
#include "TGA/TGAColor.h"
#include "Canvas.h"

Canvas::Canvas() : Canvas(1920, 1080) { }

Canvas::Canvas(unsigned int width, unsigned int height) {
    image = TGAImage(width, height, TGAImage::Format::RGB);
}

Canvas::~Canvas() = default;

void Canvas::saveImage(const std::string &filename) const {
    auto finalName = filename.find(".tga") == std::string::npos ? filename + ".tga" : filename;
    image.write_tga_file(finalName);
}

void Canvas::saveImage(const char *filename) const {
    saveImage(std::string(filename));
}

void Canvas::putPixel(const int x, const int y, const TGAColor &color) {
    // Transform cartesian Canvas coordinates to screen/image coordinates: (0, 0) in top-left
    unsigned int imageX = (image.width() / 2) + x;
    unsigned int imageY = (image.height() / 2) - y;

    image.set(imageX, imageY, color);
}

unsigned int Canvas::width() const {
    return image.width();
}

unsigned int Canvas::height() const {
    return image.height();
}
