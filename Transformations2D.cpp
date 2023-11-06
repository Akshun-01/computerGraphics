#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void translate(int& x, int& y, int dx, int dy) {
    x += dx;
    y += dy;
}

void rotate(int& x, int& y, double angle) {
    double radian = angle * 3.14159265 / 180;
    int xNew = round(x * cos(radian) - y * sin(radian));
    int yNew = round(x * sin(radian) + y * cos(radian));
    x = xNew;
    y = yNew;
}

void scale(int& x, int& y, double sx, double sy) {
    x = round(x * sx);
    y = round(y * sy);
}

void reflect(int& x, int& y, bool xReflect, bool yReflect) {
    if (xReflect) {
        x = -x;
    }
    if (yReflect) {
        y = -y;
    }
}

void shear(int& x, int& y, double shx, double shy) {
    int xNew = x + shx * y;
    int yNew = y + shy * x;
    x = xNew;
    y = yNew;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;
    
    // Draw a rectangle before transformation
    drawRectangle(x1, y1, x2, y2);
    
    // Perform transformations
    translate(x1, y1, 50, 50);
    rotate(x2, y2, 45);
    scale(x1, y1, 1.5, 1.5);
    reflect(x2, y2, true, false);
    shear(x1, y1, 0.5, 0.5);
    
    // Draw the transformed rectangle
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}

