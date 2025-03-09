/* 1. Draw the circle using mid point circle algorithm.

Algorithm:
Step 1: Start
Step 2: Setting the circle center (xc, yc) and radius r.
Step 3: Using a decision parameter p to determine when to move horizontally or vertically.
Step 4: Plotting points in all 8 octants of the circle.
Step 5: Updating the decision parameter and coordinates until the circle is fully drawn.
Step 6: Closing the graphics window after drawing.
Step 7: Stop
*/

#include <iostream>
#include <graphics.h>

void midpointCircle(int xc, int yc, int r) {
    int x = r, y = 0;
    int p = 1 - r;

    while (x >= y) {
        putpixel(xc + x, yc - y, WHITE); // (x, -y)
        putpixel(xc - x, yc - y, WHITE); // (-x, -y)
        putpixel(xc + x, yc + y, WHITE); // (x, y)
        putpixel(xc - x, yc + y, WHITE); // (-x, y)
        putpixel(xc + y, yc - x, WHITE); // (y, -x)
        putpixel(xc - y, yc - x, WHITE); // (-y, -x)
        putpixel(xc + y, yc + x, WHITE); // (y, x)
        putpixel(xc - y, yc + x, WHITE); // (-y, x)

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

    int xc = 320, yc = 240, r = 100;
    midpointCircle(xc, yc, r);

    getch();
    closegraph();

    return 0;
}
