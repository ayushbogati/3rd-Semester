/*2. Implement Bresenham's Line Drawing Algorithm (BSA)

Algorithm:
Step 1: Start
Step 1: Initialize graphics mode.
Step 1: Get (x0, y0) and (x1, y1) from the user.
Step 1: Compute dx = |x1 - x0|, dy = |y1 - y0|.
Step 1: Set sx and sy based on the start and end points.
Step 1: err = dx - dy.
Step 1: Use a loop to plot each point, updating x0 and y0 based on the error term.
Step 1: Terminate when the line reaches (x1, y1).
Step 1: Close graphics after drawing.
Step 1: Stop
*/

#include <iostream>
#include <graphics.h>

using namespace std;

void bresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x0, y0, WHITE);
        if (x0 == x1 && y0 == y1) break;

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0, y0, x1, y1;
    cout << "Enter the coordinates of the first point (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter the coordinates of the second point (x1, y1): ";
    cin >> x1 >> y1;

    bresenham(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
