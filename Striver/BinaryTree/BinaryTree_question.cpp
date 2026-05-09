#include <climits>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

// Q1. Height of binary tree :
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

int heightOfBinaryTree(Node *root) {
  if (root == NULL) {
    return 0;
  }
  int left = heightOfBinaryTree(root->left);
  int right = heightOfBinaryTree(root->right);
  return 1 + max(left, right);
}

// Balanced binary tree :
// A balanced binary tree is a binary tree in which the height of the left and
// right subtrees of every node differ by no more than 1.
// https://leetcode.com/problems/balanced-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

int isBalanced(Node *root) {

  // Brute force
  //  if(root == NULL){
  //      return true;
  //  }
  //  int leftH = heightOfBinaryTree(root->left);
  //  int rightH = heightOfBinaryTree(root ->right);
  //  if(abs(leftH-rightH) > 1) return false;
  //  bool leftBool = isBalanced(root->left);
  //  bool rightBool = isBalanced(root->right);
  //  if(!leftBool || !rightBool) return false;
  //  else return true;

  if (root == NULL) {
    return 0;
  }

  int left = isBalanced(root->left);
  int right = isBalanced(root->right);

  if ((left == -1) || (right == -1))
    return -1;
  if (abs(left - right) > 1)
    return -1;

  return 1 + max(left, right);
}

int diameterOfTree(Node *&root, int &diameter) {
  if (root == NULL)
    return 0;

  int leftH = diameterOfTree(root->left, diameter);
  int rightH = diameterOfTree(root->right, diameter);

  diameter = max(diameter, leftH + rightH); // edges
  return 1 + max(leftH, rightH);            // returning height
}

int maxPathSum(Node *&root, int &maxSum) {
  if (root == NULL)
    return 0;

  int left = max(0, maxPathSum(root->left, maxSum));
  int right = max(0, maxPathSum(root->right, maxSum));

  maxSum = max(maxSum, left + right + root->data);

  return (root->data + max(left, right));
}

bool isSameTree(Node *root, Node *root2) {
  //   if (root == NULL && root2 == NULL) // base case 1
  //     return true;
  //   if (root == NULL || root2 == NULL) // base case 2
  //     return false;
  if (root == NULL || root2 == NULL) {
    return (root == root2);
  }

  return (root->data == root2->data) && isSameTree(root->left, root2->left) &&
         isSameTree(root->right, root2->right);
}

vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;

  queue<Node *> q;
  q.push(root);
  q.push(nullptr);
  vector<int> temp;

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if (curr != nullptr) {
      temp.push_back(curr->data);
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    } else {
      if (!q.empty()) {
        ans.push_back(temp);
        temp.clear();
        q.push(nullptr);
      }
    }
  }
  ans.push_back(temp);
  return ans;
}

Node *invertTree(Node *root) {
  if (root == NULL)
    return NULL;

  Node *newNode = new Node(root->data);
  newNode->left = invertTree(root->right);
  newNode->right = invertTree(root->left);

  return newNode;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=problem-list-v2&envId=wfmvdse3
Node *lowerestAncestor(Node *&root, Node *p, Node *q) {
  if (root == NULL || root == p || root == q)
    return root;

  Node *left = lowerestAncestor(root->left, p, q);
  Node *right = lowerestAncestor(root->right, p, q);
}

bool getPath(Node *root, vector<int> &v, int target) {
  // 1. Base case: if root is null, target isn't here
  if (root == NULL)
    return false;
  // 2. Add current node to the path
  v.push_back(root->data);
  // 3. Check if current node is the target
  if (root->data == target)
    return true;
  // 4. Recursively check left and right subtrees
  if (getPath(root->left, v, target) || getPath(root->right, v, target)) {
    return true;
  }
  // 5. Backtrack: if target not found in subtrees, remove current node
  v.pop_back();
  return false;
}

void rootToNodePath(Node *&root, int target) {
  vector<int> v;
  getPath(root, v, target);
  for (auto it : v) {
    cout << it << " ";
  }
}

int main() {
  // 3,9,20,null,null,15,7
  Node *root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);
  cout << "Height of binary tree is: " << heightOfBinaryTree(root) << endl;

  // 1,2,2,3,3,null,null,4,4
  Node *root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(2);
  root2->left->left = new Node(3);
  root2->left->right = new Node(3);
  root2->right->left = new Node(4);
  root2->right->right = new Node(4);
  if (isBalanced(root2) == -1)
    cout << "The binary tree is not balanced" << endl;
  else
    cout << "The binary tree is balanced" << endl;

  int diameter = 0;
  diameterOfTree(root, diameter);
  cout << "Diameter of binary tree is: " << diameter << endl;

  int maxSum = INT_MIN;
  maxPathSum(root, maxSum);
  cout << "Maximum path sum is: " << maxSum << endl;

  // Test case with negative values: [-10, 9, 20, null, null, 15, 7]
  Node *root3 = new Node(-10);
  root3->left = new Node(9);
  root3->right = new Node(20);
  root3->right->left = new Node(15);
  root3->right->right = new Node(7);
  maxSum = INT_MIN;
  maxPathSum(root3, maxSum);
  cout << "Maximum path sum with negative root (-10): " << maxSum << endl;

  Node *root4 = new Node(1);
  root4->left = new Node(2);
  root4->right = new Node(3);
  Node *root5 = new Node(1);
  root5->left = new Node(2);
  root5->right = new Node(3);
  if (isSameTree(root4, root5))
    cout << "The binary trees are same" << endl;
  else
    cout << "The binary trees are not same" << endl;

  vector<vector<int>> ans = levelOrder(root);
  for (auto it : ans) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }

  Node *root6 = invertTree(root);
  vector<vector<int>> ans2 = levelOrder(root6);
  for (auto it : ans2) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }

  Node *root7 = new Node(1);
  root7->left = new Node(2);
  root7->right = new Node(3);
  root7->left->left = new Node(4);
  root7->left->right = new Node(5);
  root7->right->left = new Node(6);
  root7->right->right = new Node(7);
  Node *tree = NULL;
  tree = invertTree(root7);
  vector<vector<int>> ans3 = levelOrder(root7);
  cout << "Original tree: " << endl;
  for (auto it : ans3) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << "Inverted tree: " << endl;
  vector<vector<int>> ans4 = levelOrder(tree);
  for (auto it : ans4) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }

  return 0;
}