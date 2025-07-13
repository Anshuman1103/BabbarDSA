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
    
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    //1 3 7 -1 —1 11 -1 -1 5 17 -1 -1 -1
    //levelOrderTraversal(root);

    return 0;
}