#include<iostream>
#include <vector>
using namespace std;

//Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// void inOrder(Node* node, vector<int>& res) {
//     if (node == nullptr)
//         return;
        
//     // Traverse the left subtree first
//     inOrder(node->left, res);
    
//     // Visit the current node
//     res.push_back(node->data);
    
//     // Traverse the right subtree last
//     inOrder(node->right, res);
// }

// int main() {
//     // Create binary tree
//     //       1
//     //      /  \
//     //    2     3
//     //   / \     \
//     //  4   5     6
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->right = new Node(6);

//     vector<int> res;
//     inOrder(root, res);
    
//     for( int node : res) 
//         cout << node << " ";

//     return 0;
// }