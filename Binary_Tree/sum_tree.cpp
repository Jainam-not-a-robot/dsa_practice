#include<bits/stdc++.h>
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

    int sum_tree(Node* root){
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return root->data;
        int leftsum=sum_tree(root->left);
        int rightsum=sum_tree(root->right);
        return leftsum+rightsum;
    }
};

int main() {
    // Build a small tree:
    //       10
    //      /  \
    //     5    20
    //    / \     \
    //   1   8     30

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(30);

    cout << "Sum of leaf nodes: " << root->sum_tree(root) << endl;

    return 0;
}