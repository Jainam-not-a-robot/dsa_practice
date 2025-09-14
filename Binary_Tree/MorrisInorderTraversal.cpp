// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* findNode(TreeNode* curr) {
    if (curr == NULL || curr->left == NULL) return NULL;
    TreeNode* predecessor = curr->left;
    while(predecessor->right != NULL && predecessor->right != curr) {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void MorrisInorderTraversal(TreeNode* root){
    
    while(root != NULL){
        if(root->left == NULL){
            cout << root->val << ' ';
            root = root->right;
        }
        else{
            TreeNode* IP = findNode(root);
            if(IP->right == NULL){
                IP->right = root;
                root = root->left;
            }
            else{
                IP->right = NULL;
                cout << root->val << ' ';
                root = root->right;
            }
        }
    }
}

int main() {
    // Create a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    cout<<"Program started"<<endl;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Morris Inorder Traversal: ";
    MorrisInorderTraversal(root);
    cout << endl;

    return 0;
}