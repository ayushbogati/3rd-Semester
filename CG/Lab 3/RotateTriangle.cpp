/*Q1. Rotate a triangle A(40, 70), B(50, 50),
and C(30, 60)  by 45 degree in counter
clockwise direction about an arbitrary pivot point(30, 30).

Algorithm:
Step 1: Start
Step 2: Set original coordinates (Ax, Ay), (Bx, By), (Cx, Cy).
Step 3: Set pivot (Px, Py).
Step 4: Convert 45° to radians.
Step 5: Compute new points using rotation transformation.
Step 6: Print new (Ax', Ay'), (Bx', By'), (Cx', Cy').
Step 7: Return successfully.
Step 8: Stop
*/

#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main() {
    // Given triangle points
    float Ax = 40, Ay = 70;
    float Bx = 50, By = 50;
    float Cx = 30, Cy = 60;

    // Pivot point
    float Px = 30, Py = 30;

    // Angle in radians
    float angle = 45 * (PI / 180.0);

    // Rotation formula
    float newAx = Px + (Ax - Px) * cos(angle) - (Ay - Py) * sin(angle);
    float newAy = Py + (Ax - Px) * sin(angle) + (Ay - Py) * cos(angle);

    float newBx = Px + (Bx - Px) * cos(angle) - (By - Py) * sin(angle);
    float newBy = Py + (Bx - Px) * sin(angle) + (By - Py) * cos(angle);

    float newCx = Px + (Cx - Px) * cos(angle) - (Cy - Py) * sin(angle);
    float newCy = Py + (Cx - Px) * sin(angle) + (Cy - Py) * cos(angle);

    // Display results
    cout << "Rotated Triangle Points:\n";
    cout << "A'(" << newAx << ", " << newAy << ")\n";
    cout << "B'(" << newBx << ", " << newBy << ")\n";
    cout << "C'(" << newCx << ", " << newCy << ")\n";

    return 0;
}



