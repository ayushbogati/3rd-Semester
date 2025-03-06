

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class linklist{
    Node* head;
    int count;
public:
    linklist(){
        head = NULL;
        count = 0;
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;  // Last node points to new head
            head = newNode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Circular link
        }
    }

    // Insert at a specific position
    void insertAtSpecificPosition(int value, int pos){
        Node* newNode = new Node();
        newNode->data = value;

        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            int currentPos = 1;

             while (temp->next != head && currentPos < pos - 1) {
                temp = temp->next;
                currentPos++;
            }

            if (currentPos == pos - 1) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "Position out of range.\n";
            }
        }
    }

    // Delete the first node
    void deleteAtBeginning(){
        if (head == NULL) {
            cout << "Empty list.\n";
        } else if (head->next == head) {
            cout << head->data << " is deleted.\n";
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;  // Move head to the next node
            last->next = head;  // Last node points to the new head
            cout << temp->data << " is deleted.\n";
            delete temp;
        }
    }

    // Delete the last node
    void deleteAtEnd(){
        if (head == NULL) {
            cout << "Empty list.\n";
        } else if (head->next == head) {
            cout << head->data << " is deleted.\n";
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {  // Traverse to the second last node
                temp = temp->next;
            }

            cout << temp->next->data << " is deleted.\n";
            delete temp->next;
            temp->next = head;  // Last node's next points to the head
        }
    }

    // Delete at a specific position
    void deleteAtSpecificPosition(int pos){
        if (head == NULL) {
            cout << "Empty list.\n";
            return;
        }

        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        int currentPos = 1;

        while (temp->next != head && currentPos < pos - 1) {
            temp = temp->next;
            currentPos++;
        }

        if (currentPos == pos - 1 && temp->next != head) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            cout << nodeToDelete->data << " is deleted.\n";
            delete nodeToDelete;
        } else {
            cout << "Position out of range.\n";
        }
    }

    // Traverse the list
    void traversal(){
        if (head == NULL) {
            cout << "Empty list.\n";
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

int main(){
    int choice, position, data;
    string cont = "y";
    
    linklist L;
    
    while (cont == "y") {
    	cout<<"Doubly Circular Linklist"<<endl;
        cout << "1. Insert at the Beginning.\n";
        cout << "2. Insert at the End.\n";
        cout << "3. Insert at the Specific Position.\n";
        cout << "4. Delete at the Beginning.\n";
        cout << "5. Delete at the End.\n";
        cout << "6. Delete at the Specific Position.\n";
        cout << "7. Traversal.\n";
        
        cout << "Enter the Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                L.insertAtBeginning(data);
                cout << "Inserted at the beginning successfully.\n";
                break;
                
            case 2:
                cout << "Enter the data: ";
                cin >> data;
                L.insertAtEnd(data);
                cout << "Inserted at the end successfully.\n";
                break;
                
            case 3:
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the data: ";
                cin >> data;
                L.insertAtSpecificPosition(data, position);
                cout << "Inserted at the specific position successfully.\n";
                break;
                
            case 4:
                L.deleteAtBeginning();
                break;
            
            case 5:
                L.deleteAtEnd();
                break;
                
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                L.deleteAtSpecificPosition(position);
                break;
                
            case 7:
                L.traversal();
                break;
        }
        
        cout << "Do you want to continue (y/n)? ";
        cin >> cont;
    }

    return 0;
}
