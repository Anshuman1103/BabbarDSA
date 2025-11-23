#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data: "<< endl;
    cin >> data;

    root = new Node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter the left of "<< data << endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right of "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data<< " " ;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    //1 3 7 -1 —1 11 -1 -1 5 17 -1 -1 -1
    levelOrder(root);

    return 0;
}