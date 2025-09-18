#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Utility: height of a node
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility: max of two numbers
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

// Get balance factor of a node
int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maxVal(height(y->left), height(y->right)) + 1;
    x->height = maxVal(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = maxVal(height(x->left), height(x->right)) + 1;
    y->height = maxVal(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert node in AVL tree
Node* insert(Node* root, int key) {
    // 1. Perform normal BST insert
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else // Equal keys not allowed
        return root;

    // 2. Update height
    root->height = 1 + maxVal(height(root->left), height(root->right));

    // 3. Get balance factor
    int balance = getBalance(root);

    // 4. Balance the tree
    // Case 1: Left Left
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // Case 2: Right Right
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // Case 3: Left Right
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Get inorder successor (minimum value node)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete node in AVL tree
Node* deleteNode(Node* root, int key) {
    // 1. Perform standard BST delete
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) { // No child
                temp = root;
                root = nullptr;
            } else { // One child
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children: get inorder successor
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    // 2. Update height
    root->height = 1 + maxVal(height(root->left), height(root->right));

    // 3. Get balance factor
    int balance = getBalance(root);

    // 4. Balance the tree
    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal of AVL tree: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node
    root = deleteNode(root, 40);

    cout << "After deleting 40: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
