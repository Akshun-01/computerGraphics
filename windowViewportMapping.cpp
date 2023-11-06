#include <iostream>
#include <graphics.h>

// Function to perform window-viewport mapping
void mapWindowToViewport(
    int x, int y, int& mappedX, int& mappedY, int winWidth, int winHeight, int vpWidth, int vpHeight) {
    // Scale and translate coordinates from the logical window to the viewport
    mappedX = (int)((x / (float)winWidth) * vpWidth);
    mappedY = (int)((y / (float)winHeight) * vpHeight);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the logical window size
    int winWidth = 800;
    int winHeight = 600;

    // Define the viewport size
    int vpWidth = 400;
    int vpHeight = 300;

    // Define the logical window coordinates
    int x1 = 100, y1 = 100;
    int x2 = 500, y2 = 400;

    // Map logical window coordinates to viewport
    int mappedX1, mappedY1, mappedX2, mappedY2;
    mapWindowToViewport(x1, y1, mappedX1, mappedY1, winWidth, winHeight, vpWidth, vpHeight);
    mapWindowToViewport(x2, y2, mappedX2, mappedY2, winWidth, winHeight, vpWidth, vpHeight);

    // Draw a rectangle in the viewport
    rectangle(mappedX1, mappedY1, mappedX2, mappedY2);

    getch();
    closegraph();

    return 0;
}

