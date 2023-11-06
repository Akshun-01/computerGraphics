#include <iostream>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int slope_sign = (x1 < x2) ? 1 : -1;

    int x = x1;
    int y = y1;

    int interchange = 0;

    if (dy > dx) {
        std::swap(dx, dy);
        interchange = 1;
    }

    int p = 2 * dy - dx;

    for (int i = 0; i <= dx; i++) {
        putpixel(x, y, WHITE);

        if (p >= 0) {
            if (interchange == 0) {
                y += slope_sign;
            } else {
                x += slope_sign;
            }
            p = p - 2 * dx;
        }

        if (interchange == 0) {
            x += slope_sign;
        } else {
            y += slope_sign;
        }

        p = p + 2 * dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100; // Starting point
    int x2 = 500, y2 = 400; // Ending point

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}

