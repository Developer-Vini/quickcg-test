#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "quickcg.h"
using namespace QuickCG;
using namespace std;

int main(int argc, char *argv[]){
    screen(256, 256, "Teste Script");

    for(int x = 0; x < w; x++)
    for(int y = 0; y < h; y++){
        pset(x, y, ColorRGB(x, y, 128));
    }
    redraw();
    sleep();
}