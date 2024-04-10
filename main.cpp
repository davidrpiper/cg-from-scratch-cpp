#include "TGA/TGAColor.h"
#include "Canvas.h"

// The basic dumb line drawer to test TGA boilerplate
void testLine(int x0, int y0, int x1, int y1, Canvas &canvas, TGAColor color) {
    for (float t = 0; t < 1; t += 0.001) {
        int x = x0 + (x1 - x0) * t;
        int y = y0 + (y1 - y0) * t;
        canvas.putPixel(x, y, color);
    }
}

int main() {
    auto white = TGAColor::rgba(255, 255, 255, 255);

    Canvas canvas = Canvas(1920, 1080);
    testLine(200, 200, 800, 800, canvas, white);
    canvas.saveImage("testCanvas");

    return 0;
}
