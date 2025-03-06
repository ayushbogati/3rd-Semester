
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

class linklist{
    Node *head;
    int count;        
public:
    linklist(){
        head = NULL;
        count = 0;
    }

    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAtSpecificPosition(int value, int pos){
        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            int currentPos = 1;
            
            while (temp != NULL && currentPos < pos) {
                temp = temp->next;
                currentPos++;
            }

            if (temp == NULL) {
                cout << "Position out of range.\n";
                return;
            }

            // Insert at the beginning
            if (pos == 1) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } 
            // Insert at middle or end
            else {
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev != NULL) {
                    temp->prev->next = newNode;
                }
                temp->prev = newNode;
            }
        }
    }

    void deleteAtBeginning(){
        if (head == NULL) {
            cout << "Empty linklist.\n";
        } else {
            Node* temp = head;
            if (head->next == NULL) {
                cout << head->data << " is deleted.\n";
                delete head;
                head = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
                cout << temp->data << " is deleted.\n";
                delete temp;
            }
        }
    }

    void deleteAtEnd(){
        if (head == NULL) {
            cout << "Empty linklist.\n";
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            if (temp->prev != NULL) {
                temp->prev->next = NULL;
            } else {
                head = NULL;  // If the list has only one element
            }
            cout << temp->data << " is deleted.\n";
            delete temp;
        }
    }

    void deleteAtSpecificPosition(int pos){
        if (head == NULL) {
            cout << "Empty linklist.\n";
            return;
        }

        Node* temp = head;
        int currentPos = 1;

        while (temp != NULL && currentPos < pos) {
            temp = temp->next;
            currentPos++;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        // Deleting first node
        if (pos == 1) {
            deleteAtBeginning();
        } else {
            // If it's the last node
            if (temp->next == NULL) {
                deleteAtEnd();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                cout << temp->data << " is deleted.\n";
                delete temp;
            }
        }
    }

    void traversal(){
        if (head == NULL) {
            cout << "Empty list.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    int choice, position, data;
    string cont = "y";
    
    linklist L;
    
    while (cont == "y") {
    	cout <<"Menu Driven of Circular linklist:"<<endl;
        cout << "1. Insert at the Beginning.\n";
        cout << "2. Insert at the End.\n";
        cout << "3. Insert at the Specific Position.\n";
        cout << "4. Delete at the Beginning.\n";
        cout << "5. Delete at the End.\n";
        cout << "6. Delete at the Specific Position.\n";
        cout << "7. Traversal.\n";
        
        cout << "Enter the Choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                L.insertAtBeginning(data);
                cout << "Inserted at the Beginning of Linklist successfully.\n";
                break;
                
            case 2:
                cout << "Enter the data: ";
                cin >> data;
                L.insertAtEnd(data);
                cout << "Inserted at the End of Linklist successfully.\n";
                break;
                
            case 3: 
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the data: ";
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
                cout << "Enter the position: ";
                cin >> position;
                L.deleteAtSpecificPosition(position);
                cout << "Deleted successfully at the Specific Position.\n";
                break;
                
            case 7:
                L.traversal();
                break;
        }
        
        cout << "\nWant to continue (y/n): ";
        cin >> cont;
    }

    return 0;
}
