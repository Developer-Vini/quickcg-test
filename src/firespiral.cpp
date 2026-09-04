#include <cmath>
#include "quickcg.h"
using namespace QuickCG;

int main() {
    screen(600, 600, "Espiral de Fogo");
    double t = 0.0;
    while (!done()) {
        cls(ColorRGB(5, 3, 10));
        for (int i = 0; i < 400; i++) {
            double angle = i * 0.15 + t;
            double r = 3.0 * i;
            int x = 300 + (int)(cos(angle) * r);
            int y = 300 + (int)(sin(angle) * r);
            if (x >= 0 && x < w && y >= 0 && y < h) {
                unsigned char red = 180 + sin(t + i * 0.05) * 75;
                unsigned char green = 60 + sin(t * 0.6 + i * 0.08) * 60;
                pset(x, y, ColorRGB(red, green, 30));
            }
        }
        redraw();
        t += 0.02;
    }
    return 0;
}
