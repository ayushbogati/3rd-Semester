#include <iostream>

using namespace std;

// Function to perform Bubble Sort and print every pass
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        cout << "Pass " << i + 1 << ": "; // Display pass number

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Print array after each pass
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (!swapped) {
            break; // Stop early if no swaps occurred
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]); // Calculate array size

    cout << "Unsorted array: ";
    printArray(data, n);
    cout << endl;

    bubbleSort(data, n); // Sort and show each pass

    cout << "\nSorted array: ";
    printArray(data, n);

    return 0;
}

