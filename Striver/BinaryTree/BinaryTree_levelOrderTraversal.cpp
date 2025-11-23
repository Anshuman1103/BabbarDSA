#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int d;
    cout << "Enter the data: " << endl;
    cin >> d;

    root = new Node(d);

    if (d == -1)
    {
        return NULL;
    }

    cout << "Inserting the left of " << d << endl;
    root->left = buildTree(root->left);
    cout << "Inserting the right of " << d << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    // Code by babbar
    //  queue<Node*> q;
    //  q.push(root);
    //  q.push(NULL);// NULL is the seperator used to identify that the particular level is completed

    // while(!q.empty()){

    //     Node* temp = q.front();
    //     q.pop();

    //     if(temp == NULL){
    //         //Previous level completed
    //         cout << endl;
    //         if(!q.empty()){
    //             //queue still have elements
    //             q.push(NULL);
    //         }
    //     }
    //     else{
    //         cout << temp->data << " ";
    //         if(temp->left){
    //             q.push(temp->left);
    //         }
    //         if(temp->right){
    //             q.push(temp->right);
    //         }
    //     }
    // }

    // LEVEL ORDER TRAVESAL IN SAME LINE
    // queue<Node*> q;
    // q.push(root);
    // vector<int> ans;

    // while(!q.empty()){
    //     Node* t = q.front();
    //     if(t->left){
    //         q.push(t->left);
    //     }
    //     if(t->right){
    //         q.push(t->right);
    //     }
    //     q.pop();
    //     ans.push_back(t->data);

    // }
    // for(auto i : ans){
    //     cout << i << " ";
    // }

    // LEVEL ORDER TRAVERSAL FOR DIFFERENT LINES
    queue<Node *> q;
    vector<vector<int>> ans;
    q.push(root);
    q.push(NULL);
    vector<int> t;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            ans.push_back(t); // Store current level
            t.clear();

            if (!q.empty())
            {
                q.push(NULL); // Add level marker for next level
            }
        }
        else
        {
            t.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    for (auto i : ans)
    {
        cout << endl;
        for (auto j : i)
            cout << j << " ";
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 —1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    return 0;
}