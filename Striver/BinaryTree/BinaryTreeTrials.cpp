#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Build tree (level order input, -1 means NULL)
Node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->left = new Node(val);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            curr->right = new Node(val);
            q.push(curr->right);
        }
    }
    return root;
}

// Print tree (level order)
void printTree(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    cout << "\nLevel Order Traversal: ";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "\n";
}

int main() {
    Node* root = buildTree();
    //printTree(root);
    

    return 0;
}
