#include <iostream>
using namespace std;

// Node structure for Stack
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Stack Class
class Stack {
private:
    Node* top;
public:
    Stack() : top(NULL) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack stack;
    cout << "Stack Operations:" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();
    cout << "Top of stack: " << stack.peek() << endl;
    return 0;
}
