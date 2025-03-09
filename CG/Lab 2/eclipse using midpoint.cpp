/*2. Draw the eclipse using mid point eclipse algorithm.

Algorithm:
Step 1: Start
Step 2: Start from (x = 0, y = b).
Step 3: Use decision parameter p1 to determine if the next point should be horizontal or diagonal.
Step 4: Update dx and dy accordingly.
Step 5: Once Region 1 is complete, switch to the lower half of the ellipse.
Step 6: Use decision parameter p2 for determining horizontal or diagonal movement.
Step 7: Update dx and dy as needed.
Step 8: For each valid point, plot symmetric points in all four quadrants.
Step 9: Stop
*/

#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

void midpointEllipse(int centerX, int centerY, int a, int b) {
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int twoa2 = 2 * a2, twob2 = 2 * b2;
    int dx = 0, dy = twoa2 * y;

    putpixel(centerX + x, centerY + y, WHITE);
    putpixel(centerX - x, centerY + y, WHITE);
    putpixel(centerX + x, centerY - y, WHITE);
    putpixel(centerX - x, centerY - y, WHITE);

    int p1 = b2 - a2 * b + a2 / 4;
    while (dx < dy) {
        x++;
        dx += twob2;
        if (p1 < 0) {
            p1 += b2 + dx;
        } else {
            y--;
            dy -= twoa2;
            p1 += b2 + dx - dy;
        }
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
    }

    int p2 = b2 * (x + 1) * (x + 1) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        y--;
        dy -= twoa2;
        if (p2 > 0) {
            p2 += a2 - dy;
        } else {
            x++;
            dx += twob2;
            p2 += a2 - dy + dx;
        }
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
    }
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 320, centerY = 240;
    int a = 200, b = 100;

    midpointEllipse(centerX, centerY, a, b);

    getch();
    closegraph();
    return 0;
}
