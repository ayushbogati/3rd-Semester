/*Q2. Implement the Sutherland-Hodgeman Polygon Clipping Algorithm

Algorithm:
Step 1: Start
Step 2: Start graphics mode.
Step 3: Get vertices from the user.
Step 4: Get (xminp, yminp, xmaxp, ymaxp).
Step 5: Display the polygon in red.
Step 6: Display the clipping rectangle.
Step 7: Apply Sutherland-Hodgman algorithm for all four edges.
Step 8: Display the final clipped polygon in green.
Step 9: Print the new vertices.
Step 10: Pause for user input, then close graphics mode.
Step 11: Stop*/


#include <iostream>
#include <vector>
#include <graphics.h>  // Requires WinBGIm graphics library

using namespace std;

// Structure to store a point
struct Point {
    float x, y;
};

// Define the clipping window boundaries
float xminp, yminp, xmaxp, ymaxp;

// Function to check if a point is inside a given boundary
bool isInside(Point p, int edge) {
    switch (edge) {
        case 0: return (p.x >= xminp);  // Left boundary
        case 1: return (p.x <= xmaxp);  // Right boundary
        case 2: return (p.y >= yminp);  // Bottom boundary
        case 3: return (p.y <= ymaxp);  // Top boundary
    }
    return false;
}

// Function to calculate intersection of a line with a boundary
Point getIntersection(Point p1, Point p2, int edge) {
    Point intersection;
    float m;

    if (p1.x == p2.x) { // Avoid division by zero for vertical lines
        m = 1e9;  // Large value approximation for an almost-vertical slope
    } else {
        m = (p2.y - p1.y) / (p2.x - p1.x); // Slope
    }

    switch (edge) {
        case 0: // Left boundary
            intersection.x = xminp;
            intersection.y = p1.y + m * (xminp - p1.x);
            break;
        case 1: // Right boundary
            intersection.x = xmaxp;
            intersection.y = p1.y + m * (xmaxp - p1.x);
            break;
        case 2: // Bottom boundary
            intersection.y = yminp;
            if (m != 1e9)
                intersection.x = p1.x + (yminp - p1.y) / m;
            else
                intersection.x = p1.x;
            break;
        case 3: // Top boundary
            intersection.y = ymaxp;
            if (m != 1e9)
                intersection.x = p1.x + (ymaxp - p1.y) / m;
            else
                intersection.x = p1.x;
            break;
    }
    return intersection;
}

// Function to clip the polygon using the Sutherland-Hodgman algorithm
vector<Point> clipPolygon(vector<Point> polygon, int edge) {
    vector<Point> newPolygon;
    int n = polygon.size();

    for (int i = 0; i < n; i++) {
        Point current = polygon[i];
        Point next = polygon[(i + 1) % n];

        bool currentInside = isInside(current, edge);
        bool nextInside = isInside(next, edge);

        if (currentInside && nextInside) {
            newPolygon.push_back(next);
        } else if (currentInside && !nextInside) {
            newPolygon.push_back(getIntersection(current, next, edge));
        } else if (!currentInside && nextInside) {
            newPolygon.push_back(getIntersection(current, next, edge));
            newPolygon.push_back(next);
        }
    }

    return newPolygon;
}

// Function to draw the polygon
void drawPolygon(vector<Point> polygon, int color) {
    int n = polygon.size();
    setcolor(color);
    for (int i = 0; i < n; i++) {
        int x1 = polygon[i].x, y1 = polygon[i].y;
        int x2 = polygon[(i + 1) % n].x, y2 = polygon[(i + 1) % n].y;
        line(x1, y1, x2, y2);
    }
}

// Function to draw the clipping window
void drawClippingWindow() {
    setcolor(WHITE);
    rectangle(xminp, yminp, xmaxp, ymaxp);
}

int main() {
    int n;
    cout << "Enter number of vertices in polygon: ";
    cin >> n;

    vector<Point> polygon(n);
    cout << "Enter vertices (x, y):\n";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    cout << "Enter clipping window (xminp yminp xmaxp ymaxp): ";
    cin >> xminp >> yminp >> xmaxp >> ymaxp;

    // Initialize graphics mode (Fix: Changed "" to NULL)
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw original polygon in RED
    drawPolygon(polygon, RED);

    // Draw clipping window
    drawClippingWindow();

    // Clip against all four edges
    for (int edge = 0; edge < 4; edge++) {
        polygon = clipPolygon(polygon, edge);
    }

    // Draw clipped polygon in GREEN
    drawPolygon(polygon, GREEN);

    // Display final clipped polygon coordinates
    cout << "Clipped Polygon vertices:\n";
    for (int i = 0; i < polygon.size(); i++) {
        cout << "(" << polygon[i].x << ", " << polygon[i].y << ")\n";
    }

    getch(); // Wait for key press
    closegraph(); // Close graphics window

    return 0;
}

