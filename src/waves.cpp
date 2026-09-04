#include <cmath>
#include "quickcg.h"
using namespace QuickCG;

int main() {
    screen(600, 400, "Ondas Coloridas");
    double t = 0.0;

    while (!done()) {
        cls(ColorRGB(5, 5, 10));
        for (int y = 50; y < 350; y++) {
            int x = 300 + 200 * sin(y * 0.02 + t) * cos(y * 0.015 - t * 0.7);
            unsigned char r = sin(t + y * 0.01) * 127 + 128;
            unsigned char g = sin(t * 0.8 + y * 0.02 + 2.0) * 127 + 128;
            unsigned char b = sin(t * 0.5 + y * 0.015 + 4.0) * 127 + 128;
            pset(x, y, ColorRGB(r, g, b));
            pset(x + 1, y, ColorRGB(r, g, b));
        }
        redraw();
        t += 0.03;
    }
    return 0;
}
