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
    int d;
    cout << "Enter the data: " << endl;
    cin >> d;
    
    root = new Node(d);

    if(d == -1){
        return NULL;
    }

    
    cout <<"Inserting the left of "<< d << endl;
    root->left = buildTree(root->left);
    cout <<"Inserting the right of "<< d << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //Previous level completed
            cout << endl;
            if(!q.empty()){
                //queue still have elements
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<< root->data << " ";
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    //1 3 7 -1 —1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    return 0;
}