/*Q1. Implement the Liang-Barsky line-clipping algorithm.

Algorithm:

Step 1: Start
Step 2: Start graphics mode.
Step 3: Set rectangle boundaries and draw it.
Step 4: Set initial line coordinates and draw it.
Step 5: Compute intersections and clip the line.
Step 6: Display the clipped line in a different color.
Step 7: Notify if the line is completely outside.
Step 8: Pause for user input, then close graphics mode.
Step 9: Stop*/

#include <iostream>
#include <graphics.h>
#include <algorithm>
using namespace std;

// Define the structure to represent the rectangular window
struct Rect {
    int x_min, y_min, x_max, y_max;
};

// Liang-Barsky Line Clipping Algorithm
bool LiangBarsky(int x1, int y1, int x2, int y2, const Rect& rect, int& clipped_x1, int& clipped_y1, int& clipped_x2, int& clipped_y2) {
    // Define the rectangle boundaries
    int p[] = {- (x2 - x1), x2 - x1, - (y2 - y1), y2 - y1};  // The direction of the line for each edge
    int q[] = {x1 - rect.x_min, rect.x_max - x1, y1 - rect.y_min, rect.y_max - y1};  // The distance from the point to the boundaries

    float t0 = 0.0f, t1 = 1.0f;  // Initial parameter values

    // For each edge of the rectangle
    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0) {
            // Line is parallel to this edge
            if (q[i] < 0) {
                // Line is outside the clipping window
                return false;
            }
        } else {
            float t = static_cast<float>(q[i]) / p[i];
            if (p[i] < 0) {
                // Clipping the farthest intersection
                t0 = max(t0, t);
            } else {
                // Clipping the nearest intersection
                t1 = min(t1, t);
            }
            if (t0 > t1) {
                return false;  // No intersection
            }
        }
    }

    // If the line segment is within the clipping window
    clipped_x1 = x1 + static_cast<int>(t0 * (x2 - x1));
    clipped_y1 = y1 + static_cast<int>(t0 * (y2 - y1));
    clipped_x2 = x1 + static_cast<int>(t1 * (x2 - x1));
    clipped_y2 = y1 + static_cast<int>(t1 * (y2 - y1));

    return true;  // Line was successfully clipped
}

int main() {
    // Initialize the graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Define the clipping rectangle (x_min, y_min, x_max, y_max)
    Rect rect = {100, 100, 300, 300};

    // Draw the clipping rectangle
    rectangle(rect.x_min, rect.y_min, rect.x_max, rect.y_max);

    // Coordinates of the line to be clipped (x1, y1, x2, y2)
    int x1 = 50, y1 = 50, x2 = 350, y2 = 350;

    // Draw the original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Variables to store the clipped line coordinates
    int clipped_x1, clipped_y1, clipped_x2, clipped_y2;

    // Apply Liang-Barsky line clipping
    if (LiangBarsky(x1, y1, x2, y2, rect, clipped_x1, clipped_y1, clipped_x2, clipped_y2)) {
        // Draw the clipped line in blue
        setcolor(BLUE);
        line(clipped_x1, clipped_y1, clipped_x2, clipped_y2);
    } else {
        outtextxy(10, 10, "Line is outside the clipping window.");
    }

    // Wait for user input to close the window
    getch();
    closegraph();

    return 0;
}
