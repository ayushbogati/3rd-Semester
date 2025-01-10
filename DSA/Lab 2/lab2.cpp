#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 5;  // Maximum size of the stack
    string stack[MAX_SIZE];         // Array to hold the stack elements
    int top;                        // Index for the top of the stack

public:
    // Constructor to initialize the stack
    Stack() : top(-1) {}

    // Make the stack empty
    void make_empty_stack() {
        top = -1;
        cout << "Stack has been reset to empty." << endl;
    }

    // Push operation
    void push(string value) {
        if (top < MAX_SIZE - 1) {
            stack[++top] = value;
            cout << value << " pushed to the stack." << endl;
        } else {
            cout << "Stack overflow! Cannot push " << value << "." << endl;
        }
    }

    // Pop operation
    void pop() {
        if (!is_empty()) {
            cout << "Popped value: " << stack[top--] << endl;
        } else {
            cout << "Stack underflow! Cannot pop." << endl;
        }
    }

    // Traverse the stack
    void traverse() {
        if (!is_empty()) {
            cout << "Stack contents are:"<<endl ;
            for (int i = top; i >= 0; --i) {
                cout << stack[i] ;
                cout<<" ";
            }
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    // Peek the top element
    void peek_top() {
        if (!is_empty()) {
            cout << "Top element is: " << stack[top] << endl;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    // Check if the stack is empty
    bool is_empty() {
        return top == -1;
    }
};

// Menu function
void menu() {
    Stack stack;
    int choice;
    string value;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Make Empty Stack" << endl;
        cout << "2. Push Operation" << endl;
        cout << "3. Pop Operation" << endl;
        cout << "4. Traverse Stack" << endl;
        cout << "5. Peek Top Element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stack.make_empty_stack();
                break;
            case 2:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 3:
                stack.pop();
                break;
            case 4:
                stack.traverse();
                break;
            case 5:
                stack.peek_top();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    menu();  // Calling the menu function to start the program
    return 0;
}
