//
// Created by David Piper on 9/4/2024.
//

#include "TGA/TGAImage.h"
#include "TGA/TGAColor.h"
#include "Canvas.h"

Canvas::Canvas() : Canvas(1920, 1080) { }

Canvas::Canvas(int width, int height) {
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

int Canvas::width() const {
    return image.width();
}

int Canvas::height() const {
    return image.height();
}

int Canvas::lowestValidX() const {
    int width = this->width();
    return -width / 2;
}

int Canvas::highestValidX() const {
    return (this->width() / 2) - 1;
}

int Canvas::lowestValidY() const {
    int height = this->height();
    return -height / 2;
}

int Canvas::highestValidY() const {
    return (this->height() / 2) - 1;
}
