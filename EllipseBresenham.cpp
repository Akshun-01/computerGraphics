#include <iostream>
#include <graphics.h>

void drawEllipseBresenham(int xc, int yc, int rx, int ry) {
    float x = 0, y = ry;
    float rx2 = rx * rx;
    float ry2 = ry * ry;
    float p1 = ry2 - rx2 * ry + 0.25 * rx2;

    while (2 * ry2 * x < 2 * rx2 * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0) {
            x++;
            p1 += 2 * ry2 * x + ry2;
        } else {
            x++;
            y--;
            p1 += 2 * ry2 * x - 2 * rx2 * y + ry2;
        }
    }

    float p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0) {
            y--;
            p2 -= 2 * rx2 * y + rx2;
        } else {
            x++;
            y--;
            p2 += 2 * ry2 * x - 2 * rx2 * y + rx2;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 300, yc = 300; // Center point of the ellipse
    int rx = 100; // X-axis radius
    int ry = 50; // Y-axis radius

    drawEllipseBresenham(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}
	
