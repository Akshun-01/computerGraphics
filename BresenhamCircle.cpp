#include <iostream>
#include <graphics.h>

void drawCircleBresenham(int centerX, int centerY, int radius) {
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    while (x <= y) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);

        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            p = p + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 300, centerY = 300; // Center point of the circle
    int radius = 100; // Radius of the circle

    drawCircleBresenham(centerX, centerY, radius);

    getch();
    closegraph();

    return 0;
}

