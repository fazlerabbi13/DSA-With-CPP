#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;
    
    // Helper function for insertion
    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        
        return node;
    }
    
    // Helper function for deletion
    Node* deleteHelper(Node* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (val < node->data) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->data) {
            node->right = deleteHelper(node->right, val);
        } else {
            // Node to be deleted found
            
            // Case 1: No child or one child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Case 2: Two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        
        return node;
    }
    
    // Find minimum value node
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Find maximum value node
    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    
    // Search helper
    // bool searchHelper(Node* node, int val) {
    //     if (node == nullptr) {
    //         return false;
    //     }
        
    //     if (node->data == val) {
    //         return true;
    //     } else if (val < node->data) {
    //         return searchHelper(node->left, val);
    //     } else {
    //         return searchHelper(node->right, val);
    //     }
    // }
    
    // Inorder traversal helper (Left-Root-Right)
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }
    
    // Preorder traversal helper (Root-Left-Right)
    void preorderHelper(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }
    
    // Postorder traversal helper (Left-Right-Root)
    void postorderHelper(Node* node) {
        if (node != nullptr) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }
    
    // Height helper
    int heightHelper(Node* node) {
        if (node == nullptr) {
            return -1; // Height of empty tree is -1
        }
        
        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    // Count nodes helper
    int countNodesHelper(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    
    // Destroy tree helper
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    
public:
    BST() {
        root = nullptr;
    }
    
    ~BST() {
        destroyTree(root);
    }
    
    // Insert a value
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    // Delete a value
    void remove(int val) {
        root = deleteHelper(root, val);
    }
    
    // Search for a value
    bool search(int val) {
        return searchHelper(root, val);
    }
    
    // Find minimum value
    int getMin() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        return findMin(root)->data;
    }
    
    // Find maximum value
    int getMax() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        return findMax(root)->data;
    }
    
    // Inorder traversal
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
    
    // Preorder traversal
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }
    
    // Postorder traversal
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }
    
    // Level order traversal (BFS)
    void levelOrder() {
        if (root == nullptr) {
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
    
    // Get height of tree
    int height() {
        return heightHelper(root);
    }
    
    // Count total nodes
    int countNodes() {
        return countNodesHelper(root);
    }
    
    // Check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }
};

// Main function with examples
int main() {
    BST tree;
    
    // Insert elements
    cout << "Inserting: 50, 30, 70, 20, 40, 60, 80" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    // Traversals
    cout << "\nInorder Traversal: ";
    tree.inorder();
    
    cout << "Preorder Traversal: ";
    tree.preorder();
    
    cout << "Postorder Traversal: ";
    tree.postorder();
    
    cout << "Level Order Traversal: ";
    tree.levelOrder();
    
    // Search
    cout << "\nSearching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;
    
    // Min and Max
    cout << "\nMinimum value: " << tree.getMin() << endl;
    cout << "Maximum value: " << tree.getMax() << endl;
    
    // Height and node count
    cout << "\nTree height: " << tree.height() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    
    // Delete
    cout << "\nDeleting 20..." << endl;
    tree.remove(20);
    cout << "Inorder after deletion: ";
    tree.inorder();
    
    cout << "\nDeleting 30..." << endl;
    tree.remove(30);
    cout << "Inorder after deletion: ";
    tree.inorder();
    
    cout << "\nDeleting 50..." << endl;
    tree.remove(50);
    cout << "Inorder after deletion: ";
    tree.inorder();
    
    return 0;
}