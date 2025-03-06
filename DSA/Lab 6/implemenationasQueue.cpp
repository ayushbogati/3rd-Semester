#incl ude <iostream>
using namespace std;

// Node structure for Queue
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Queue Class
class Queue {
private:
    Node *front, *rear;
public:
    Queue() : front(NULL), rear(NULL) {}


    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        cout << temp->data << " dequeued from queue." << endl;
        delete temp;
    }

  

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;
    cout << "Queue Operations:\n";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();

    queue.dequeue();
    queue.display();



    return 0;
}
