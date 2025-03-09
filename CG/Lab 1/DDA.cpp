/*1. Implement Digital Differential  Analyzer Algorithm (DDA)

Algorithm:
Step 1: Start
Step 2: Start graphics mode using initgraph().
Step 4: Get the starting (x1, y1) and ending (x2, y2) points from the user.
Step 4: Compute dx = x2 - x1 and dy = y2 - y1.
Step 5: Set the number of steps as the larger of |dx| and |dy|.
Step 6: Compute xInc = dx / steps and yInc = dy / steps.
Step 7: Using a loop, incrementally draw each point using putpixel().
Step 8: Add a small delay to visualize the line being drawn (delay(10)).
Step 9: Wait for user input (getch()) and then close graphics mode (closegraph()).
Step 10: Stop
*/

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    cout << "Enter coordinates (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    DDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
