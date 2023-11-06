#include <iostream>
#include <graphics.h>

// Define the clipping window coordinates
int xmin = 100, ymin = 100, xmax = 500, ymax = 400;

// Liang-Barsky line clipping algorithm
bool clipLine(int& x1, int& y1, int& x2, int& y2) {
    double t1 = 0.0, t2 = 1.0;
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate the parameters for the clipping edges
    int p[4] = { -dx, dx, -dy, dy };
    int q[4] = { x1 - xmin, xmax - x1, y1 - ymin, ymax - y1 };

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return false; // Line is parallel and outside the edge
        } else {
            double t = (double)q[i] / p[i];
            if (p[i] < 0) {
                if (t > t2)
                    return false; // Line enters from the outside
                else if (t > t1)
                    t1 = t; // Line exits
            } else if (p[i] > 0) {
                if (t < t1)
                    return false; // Line enters from the outside
                else if (t < t2)
                    t2 = t; // Line exits
            }
        }
    }

    // Calculate the clipped endpoints
    int x1_new = x1 + t1 * dx;
    int y1_new = y1 + t1 * dy;
    int x2_new = x1 + t2 * dx;
    int y2_new = y1 + t2 * dy;

    // Update the original coordinates
    x1 = x1_new;
    y1 = y1_new;
    x2 = x2_new;
    y2 = y2_new;

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 50, y1 = 60;
    int x2 = 600, y2 = 450;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Clip the line using Liang-Barsky
    if (clipLine(x1, y1, x2, y2)) {
        // Draw the clipped line
        setcolor(RED);
        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();

    return 0;
}

