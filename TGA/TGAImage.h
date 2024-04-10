//
// Adapted from https://github.com/ssloy/tinyrenderer
//

#ifndef CG_FROM_SCRATCH_CPP_TGAIMAGE_H
#define CG_FROM_SCRATCH_CPP_TGAIMAGE_H

#include <cstdint>
#include <fstream>
#include <vector>
#include "TGAColor.h"

#pragma pack(push,1)
struct TGAHeader {
    std::uint8_t  idlength = 0;
    std::uint8_t  colormaptype = 0;
    std::uint8_t  datatypecode = 0;
    std::uint16_t colormaporigin = 0;
    std::uint16_t colormaplength = 0;
    std::uint8_t  colormapdepth = 0;
    std::uint16_t x_origin = 0;
    std::uint16_t y_origin = 0;
    std::uint16_t width = 0;
    std::uint16_t height = 0;
    std::uint8_t  bitsperpixel = 0;
    std::uint8_t  imagedescriptor = 0;
};
#pragma pack(pop)

struct TGAImage {
    enum Format { GRAYSCALE=1, RGB=3, RGBA=4 };

    TGAImage() = default;
    TGAImage(const unsigned int w, const unsigned int h, const int bpp);
    bool  read_tga_file(const std::string filename);
    bool write_tga_file(const std::string filename) const;
    void flip_horizontally();
    void flip_vertically();
    TGAColor get(const unsigned int x, const unsigned int y) const;
    /**
     * Image pixels are set in Screen coordinates: (0, 0) is the top-left pixel.
     * Does nothing if a pixel outside the width and height of the image is specified.
     *
     * @param x coordinates go from [0 -> width-1] from left to right
     * @param y coordinates go from [0 -> height-1] from top to bottom
     * @param color to paint the pixel at the given Screen coordinates.
     */
    void set(const unsigned int x, const unsigned int y, const TGAColor &color);
    unsigned int width()  const;
    unsigned int height() const;
private:
    bool load_rle_data(std::ifstream &in);

    unsigned int w = 0;
    unsigned int h = 0;
    std::uint8_t bpp = 0;
    std::vector<std::uint8_t> data = {};
};

#endif //CG_FROM_SCRATCH_CPP_TGAIMAGE_H
