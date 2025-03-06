#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class linklist {
    Node *head;
    int count;
public:
    linklist() {
        head = NULL;
        count = 0;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        Node* temp = head;
        newNode->data = value;
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            // Traverse to the last node to maintain circular link
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Pointing to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse until the last node
                temp = temp->next;
            }
            temp->next = newNode;   // Link the last node to the new node
            newNode->next = head;   // Make the new node point back to head
        }
    }

    void insertAtSpecificPosition(int value, int pos) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            int count = 1;

            // Traverse to count nodes
            while (temp->next != head) {
                count++;
                temp = temp->next;
            }

            // Check if the position is valid
            if (pos <= 0 || pos > count + 1) {
                cout << "Position out of range.\n";
                return;
            }

            if (pos == 1) {
                newNode->next = head;
                temp->next = newNode;
                head = newNode;  
            } else {
                temp = head;
                for (int i = 1; i < pos - 1; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "Empty linklist.\n";
        } else {
            Node* temp = head;
            if (head->next == head) {
                // Only one node in the list
                cout << head->data << " is deleted from the linklist.\n";
                delete head;
                head = NULL;
            } else {
                Node* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                head = head->next;
                lastNode->next = head;
                cout << temp->data << " is deleted.\n";
                delete temp;
            }
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "Empty linklist.\n";
        } else {
            Node* temp = head;
            if (head->next == head) {
                // Only one node in the list
                cout << head->data << " is deleted from the linklist.\n";
                delete head;
                head = NULL;
            } else {
                while (temp->next->next != head) {
                    temp = temp->next;
                }
                cout << temp->next->data << " is deleted.\n";
                delete temp->next;
                temp->next = head;  // Maintain circular link
            }
        }
    }

    void deleteAtSpecificPosition(int pos) {
        if (head == NULL) {
            cout << "Empty linklist.\n";
            return;
        }

        Node* temp = head;
        int count = 1;

        // Count the number of nodes
        while (temp->next != head) {
            count++;
            temp = temp->next;
        }

        if (pos <= 0 || pos > count) {
            cout << "Position out of range.\n";
            return;
        }

        if (pos == 1) {
            Node* loc = head;
            if (head->next == head) {
                head = NULL;
            } else {
                Node* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                head = head->next;
                lastNode->next = head;
            }
            cout << loc->data << " is deleted.\n";
            delete loc;
        } else {
            temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* loc = temp->next;
            temp->next = loc->next;
            cout << loc->data << " is deleted.\n";
            delete loc;
        }
    }

    void traversal() {
        if (head == NULL) {
            cout << "Empty linklist.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int choice, position, data;
    string cont = "y";
    
    linklist L;
    
    while (cont == "y") {
        cout << "1.Insert at the Beginning.\n";
        cout << "2.Insert at the End.\n";
        cout << "3.Insert at the Specific Position.\n";
        cout << "4.Delete at the Beginning.\n";
        cout << "5.Delete at the End.\n";
        cout << "6.Delete at the Specific Position.\n";
        cout << "7.Traversal.\n";
        
        cout << "Enter the Choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the data : ";
                cin >> data;
                L.insertAtBeginning(data);
                cout << "Inserted at the Beginning of Linklist successfully.\n";
                break;
                
            case 2:
                cout << "Enter the data : ";
                cin >> data;
                L.insertAtEnd(data);
                cout << "Inserted at the End of Linklist successfully.\n";
                break;
                
            case 3:
                cout << "Enter the position : ";
                cin >> position;
                cout << "Enter the data : ";
                cin >> data;
                L.insertAtSpecificPosition(data, position);
                cout << "Inserted at the given position of Linklist successfully.\n";
                break;
                
            case 4:
                L.deleteAtBeginning();
                cout << "Deleted successfully at the beginning.\n";
                break;
            
            case 5:
                L.deleteAtEnd();
                cout << "Deleted successfully at the End.\n";
                break;
                
            case 6:
                cout << "Enter the position : ";
                cin >> position;
                L.deleteAtSpecificPosition(position);
                cout << "Deleted successfully at the Specific Position.\n";
                break;
                
            case 7:
                L.traversal();
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        
        cout << "\nWant to continue (y/n): ";
        cin >> cont;
    }

    return 0;
}

