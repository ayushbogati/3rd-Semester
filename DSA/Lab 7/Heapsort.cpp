#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index 'i'
void heapify(int arr[], int size, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest
        heapify(arr, size, largest); // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort and print each step
void heapSort(int arr[], int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Print heap after building
    cout << "Max Heap: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // Heapify the reduced heap

        // Print array after each extraction
        cout << "Heap after removing max (" << arr[i] << "): ";
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);
    cout << endl;

    heapSort(arr, size);

    cout << "\nSorted array: ";
    printArray(arr, size);

    return 0;
}

