#include <iostream>

using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        cout << "Gap: " << gap << endl; // Print current gap
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        // Print array after each pass
        cout << "Array after gap " << gap << ": ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {12, 34, 54, 2, 3, 67, 1, 98, 44};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted array: ";
    printArray(data, n);
    cout << endl;

    shellSort(data, n);

    cout << "\nSorted array: ";
    printArray(data, n);

    return 0;
}

