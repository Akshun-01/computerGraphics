#include <iostream>
#include <graphics.h>

void drawCircleMidpoint(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int p = 1 - radius;

    while (x >= y) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);

        y++;

        if (p <= 0) {
            p = p + 2 * y + 1;
        } else {
            x--;
            p = p + 2 * y - 2 * x + 1;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 300, centerY = 300; // Center point of the circle
    int radius = 100; // Radius of the circle

    drawCircleMidpoint(centerX, centerY, radius);

    getch();
    closegraph();

    return 0;
}

