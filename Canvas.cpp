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

void Canvas::saveImage(const std::string &filename) {
    auto finalName = filename.find(".tga") == std::string::npos ? filename + ".tga" : filename;
    image.write_tga_file(finalName);
}

void Canvas::saveImage(const char *filename) {
    std::string str(filename);
    saveImage(str);
}

void Canvas::putPixel(const unsigned int x, const unsigned int y, const TGAColor &color) {
    // TODO Coordinate transformation here!
    image.set(x, y, color);
}
