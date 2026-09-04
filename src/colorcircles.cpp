#include <cmath>
#include "quickcg.h"
using namespace QuickCG;

int main() {
    screen(500, 500, "Circulos Concentricos");
    cls(ColorRGB(0, 0, 0));
    double t = 0.0;
    while (!done()) {
        for (int r = 10; r < 250; r += 8) {
            unsigned char red = 100 + sin(t + r * 0.05) * 155;
            unsigned char blue = 100 + cos(t * 0.7 + r * 0.04) * 155;
            ColorRGB col(red, 30, blue);
            int x = 250 + (int)(sin(t * 0.3) * 20);
            int y = 250 + (int)(cos(t * 0.4) * 20);
            for (int a = 0; a < 360; a += 2) {
                int px = x + (int)(cos(a * M_PI / 180.0) * r);
                int py = y + (int)(sin(a * M_PI / 180.0) * r);
                if (px >= 0 && px < w && py >= 0 && py < h) pset(px, py, col);
            }
        }
        redraw();
        t += 0.04;
        cls(ColorRGB(0, 0, 0));
    }
    return 0;
}
