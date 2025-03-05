#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to partition the array
int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Swap pivot into correct position

    // Print array after partition
    cout << "Partitioned around pivot " << pivot << ": ";
    printArray(arr, size);

    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high, size); // Partitioning index

        quickSort(arr, low, pi - 1, size); // Sort elements before partition
        quickSort(arr, pi + 1, high, size); // Sort elements after partition
    }
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);
    cout << endl;

    quickSort(arr, 0, size - 1, size);

    cout << "\nSorted array: ";
    printArray(arr, size);

    return 0;
}

