#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "quickcg.h"
using namespace QuickCG;
using namespace std;

struct View {
    double cx;
    double cy;
    double zoom;
};

double mandelbrot(double cx, double cy, int maxIter) {
    double zx = 0.0, zy = 0.0;
    double zx2 = 0.0, zy2 = 0.0;
    int iter = 0;
    while (zx2 + zy2 <= 4.0 && iter < maxIter) {
        zy = 2.0 * zx * zy + cy;
        zx = zx2 - zy2 + cx;
        zx2 = zx * zx;
        zy2 = zy * zy;
        iter++;
    }
    if (iter == maxIter) return -1.0;
    double log_zn = log(zx2 + zy2) / 2.0;
    double nu = log(log_zn / log(2.0)) / log(2.0);
    return iter + 1.0 - nu;
}

ColorRGB palette(double t) {
    if (t < 0.0) return ColorRGB(0, 0, 0);
    double r = sin(t * 0.10) * 127 + 128;
    double g = sin(t * 0.13 + 2.0) * 127 + 128;
    double b = sin(t * 0.17 + 4.0) * 127 + 128;
    return ColorRGB((unsigned char)r, (unsigned char)g, (unsigned char)b);
}

void drawMandelbrot(const View& view, int maxIter) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            double cx = view.cx + (x - w / 2.0) / (view.zoom * w / 4.0);
            double cy = view.cy + (y - h / 2.0) / (view.zoom * w / 4.0);
            double val = mandelbrot(cx, cy, maxIter);
            pset(x, y, palette(val));
        }
    }
    redraw();
}

void showHelp() {
    print(
        "Fractal de Mandelbrot Interativo\n"
        "===============================\n"
        "Setas      : mover (pan)\n"
        "+ / -      : zoom in / out\n"
        "R          : resetar vista\n"
        "1 / 2 / 3  : detalhe baixo / medio / alto\n"
        "ESC        : sair\n"
    );
}

int main(int argc, char *argv[]) {
    screen(800, 600, "Mandelbrot - QuickCG");
    View view{-0.75, 0.0, 1.0};
    int maxIter = 100;
    bool showMenu = true;

    drawMandelbrot(view, maxIter);

    while (true) {
        int key = readkey();
        if (key == SDLK_ESCAPE) break;
        if (key == 'r' || key == 'R') {
            view.cx = -0.75;
            view.cy = 0.0;
            view.zoom = 1.0;
            maxIter = 100;
            drawMandelbrot(view, maxIter);
        }
        if (key == '+') {
            view.zoom *= 1.3;
            maxIter = min(maxIter + 20, 1000);
            drawMandelbrot(view, maxIter);
        }
        if (key == '-') {
            view.zoom /= 1.3;
            maxIter = max(maxIter - 20, 20);
            drawMandelbrot(view, maxIter);
        }
        double pan = 0.05 / view.zoom;
        if (key == SDLK_LEFT) {
            view.cx -= pan;
            drawMandelbrot(view, maxIter);
        }
        if (key == SDLK_RIGHT) {
            view.cx += pan;
            drawMandelbrot(view, maxIter);
        }
        if (key == SDLK_UP) {
            view.cy -= pan;
            drawMandelbrot(view, maxIter);
        }
        if (key == SDLK_DOWN) {
            view.cy += pan;
            drawMandelbrot(view, maxIter);
        }
        if (key == '1') {
            maxIter = 50;
            drawMandelbrot(view, maxIter);
        }
        if (key == '2') {
            maxIter = 150;
            drawMandelbrot(view, maxIter);
        }
        if (key == '3') {
            maxIter = 500;
            drawMandelbrot(view, maxIter);
        }
        if (key == 'h' || key == 'H') {
            if (showMenu) {
                cls(ColorRGB(0, 0, 0));
                showHelp();
                readkey();
                drawMandelbrot(view, maxIter);
            }
        }
    }
    return 0;
}
