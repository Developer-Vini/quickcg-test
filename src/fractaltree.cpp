#include <cmath>
#include "quickcg.h"
using namespace QuickCG;

void tree(int x, int y, double len, double angle, int depth) {
    if (depth == 0 || len < 2.0) return;
    int x2 = x + (int)(cos(angle) * len);
    int y2 = y + (int)(sin(angle) * len);
    unsigned char green = 100 + depth * 25;
    ColorRGB col(80 + depth * 20, green, 60);
    drawLine(x, y, x2, y2, col);
    tree(x2, y2, len * 0.72, angle - 0.5, depth - 1);
    tree(x2, y2, len * 0.72, angle + 0.5, depth - 1);
}

int main() {
    screen(800, 600, "Arvore Fractal");
    cls(ColorRGB(10, 10, 20));
    tree(400, 550, 120.0, -M_PI / 2.0, 9);
    redraw();
    sleep(2);
    return 0;
}
