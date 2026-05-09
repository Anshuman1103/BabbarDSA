#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int d){
    data = d;
    left = right = nullptr;
  }
};

Node* buildTree(Node* root){
  cout << "Enter the data;" << endl;
  int val;
  cin >> val;
  if(val == -1) return nullptr;
  root = new Node(val);
  cout << "Enter left of "<< val << endl;
  root->left = buildTree(root->left);
  cout << "Enter right of " << val << endl;
  root->right = buildTree(root->right);
  return root;
}

void levelOrder(Node* &root){
  if(root == nullptr){
    return;
  }
  queue<Node*> q;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    
  }
}

int main(){
    Node* root = nullptr;
    buildTree(root);
}
