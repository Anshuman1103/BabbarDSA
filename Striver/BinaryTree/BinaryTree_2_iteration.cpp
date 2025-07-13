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
    
}

vector<int> inorder(Node* root){
    vector<int> in;
    Node* temp = root;
    stack<Node*> st;

    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()) break;
            temp = st.top();
            in.push_back(temp->data);
            st.pop();
            temp = temp->right;
        }
    }
    return in;
}

vector<int> preorder(Node* root){
    vector<int> pre;
    if(root == NULL){
        return pre;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        pre.push_back(root->data);

        //First put right to first take out left
        if(root->right){
            st.push(root->right);
        }
        if(root->left){
            st.push(root->left);
        }
    }
    cout <<"Preorder :" << endl;
    return pre;
}

vector<int> postorder(Node* root){
    vector<int> post;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left){
            st1.push(root->left);
        }
        if(root->right){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        post.push_back(st2.top()->data);
        st2.pop();
    }
    return post;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    //1 3 7 -1 —1 11 -1 -1 5 17 -1 -1 -1
   // levelOrderTraversal(root);

    vector<int> ans;
   //ans = preorder(root);
    //ans = inorder(root);
    ans = postorder(root);
    
   for(int i : ans){
    cout << i << " ";
   }

    return 0;
}