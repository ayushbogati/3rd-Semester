#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Search Tree ADT
class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* remove(Node* node, int val) {
        if (node == nullptr) return node;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

public:
    BST() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }

    bool search(int val) { return search(root, val); }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void remove(int val) { root = remove(root, val); }
};

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Enter element to search: ";
    cin >> value;
    cout << "Search result: " << (tree.search(value) ? "Found" : "Not Found") << endl;

    cout << "Enter element to delete: ";
    cin >> value;
    tree.remove(value);

    cout << "Inorder after deletion: ";
    tree.inorder();

    return 0;
}
