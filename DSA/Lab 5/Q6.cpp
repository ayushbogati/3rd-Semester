//6.WAP TO DEMONSTRATE TOWER TOH USING RECURSIVE FUNCTION.

#include <iostream>
using namespace std;

// Function to solve the Tower of Hanoi problem using recursion
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Move one disk from source to destination
        cout << "Move disk 1 from " << source << " to " << destination << ".\n";
        return;
    }

    // Move n-1 disks from source to auxiliary using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << ".\n";

    // Move n-1 disks from auxiliary to destination using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of disks must be greater than zero.\n";
    } else {
        cout << "The steps to solve the Tower of Hanoi with " << n << " disks are:\n";
        towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are the names of the rods
    }

    return 0;
}

