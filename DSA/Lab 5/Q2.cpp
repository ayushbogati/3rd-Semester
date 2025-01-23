#include <iostream>
#define SIZE 10 // Define the maximum size of the priority queue
using namespace std;

class PriorityQueue {
private:
    int arr[SIZE];
    int count; // Keeps track of the number of elements in the queue

public:
    PriorityQueue() {
        count = 0;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == SIZE;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Priority queue is full!\n";
            return;
        }

        // Insert the new element in sorted order
        int i;
        for (i = count - 1; i >= 0 && arr[i] > value; i--) {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = value;
        count++;
        cout << value << " enqueued to the priority queue.\n";
    }

    // Function to remove the highest-priority element (smallest value)
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority queue is empty!\n";
            return;
        }

        cout << arr[0] << " dequeued from the priority queue.\n";
        for (int i = 1; i < count; i++) {
            arr[i - 1] = arr[i];
        }
        count--;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Priority queue is empty!\n";
            return;
        }

        cout << "Priority queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            pq.enqueue(value);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
