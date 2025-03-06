
//singly linklist

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    
    Node(int value) {
        data = value;
        next = NULL;  
    }
};


class SinglyLinkedList {
private:
    Node* head;

public:
    
    SinglyLinkedList() {
        head = NULL;  
    }

  
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {  
            temp = temp->next;
        }
        temp->next = newNode;
    }

   
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

  
    void insertAtPosition(int value, int position) {
       
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < position - 1) {  
            temp = temp->next;
            count++;
        }

    
        if (temp == NULL) {  
            cout << "linklist full.  please insert form end." << endl;
            insertEnd(value);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    
    void deleteBeginning() {
        if (head == NULL) {  
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

   
    void deleteEnd() {
        if (head == NULL) { 
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;  
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next != NULL) {  
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL; 
    }

   
    void deleteAtPosition(int position) {
        if (head == NULL) { 
            cout << "List is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        int count = 1;

        
        while (temp != NULL && count < position - 1) {  
            temp = temp->next;
            count++;
        }

       
        if (temp == NULL || temp->next == NULL) {  
            cout << "Position is out of bounds." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void display() {
        if (head == NULL) { 
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {  
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

   
    
};


int main() {
    SinglyLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\nMenu:"<<endl;
        cout << "1. Insert at End"<<endl;
        cout << "2. Insert at Beginning"<<endl;
        cout << "3. Insert at Specific Position"<<endl;
        cout << "4. Delete from Beginning"<<endl;
        cout << "5. Delete from End"<<endl;
        cout << "6. Delete from Specific Position"<<endl;
        cout << "7. Traverse List"<<endl;
        cout << "8. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end of the linklist: ";
                cin >> value;
                list.insertEnd(value);
                cout<<value<<" succesfully inserted at end of the linklist."<<endl;
			    break;

            case 2:
                cout << "Enter value to insert at beginning of the linklist: ";
                cin >> value;
                list.insertBeginning(value);
                   cout<<value<<" succesfully inserted at beginning of the linklist."<<endl;
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                 cout<<value<<" succesfully inserted at "<<position<<"-th position of the linklist."<<endl;
                break;

            case 4:
                list.deleteBeginning();
                cout<<"Deleted succesfully from beginning of the linklist."<<endl;
                break;

            case 5:
                list.deleteEnd();
                 cout<<"Deleted succesfully from end of the linklist."<<endl;
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                 cout<<"Deleted succesfully from "<<position<<"-th position of the linklist."<<endl;
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting program..."<<endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}              



