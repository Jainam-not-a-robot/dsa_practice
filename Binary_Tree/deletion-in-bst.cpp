#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val): val(val),left(nullptr),right(nullptr){};

    
};
void inorder(Node* root){
        if(root==NULL)return;
        inorder(root->left);
        cout<<root->val<<' ';//this line comes above for preorder and below for postorder
        inorder(root->right);
    }
Node* deleteItem(int val,Node* root){
    //pehle dhundhte hai
    if(root==NULL)return nullptr;
    if(val<root->val)root->left=deleteItem(val,root->left);
    else if(val>root->val)root->right=deleteItem(val,root->right);
    else{
        if(root->right==NULL&&root->left==NULL){
            delete(root);
            return nullptr;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        else{
            Node* temp=root->right;
            while(temp->left!=NULL)temp=temp->left;
            root->val=temp->val;
            root->right=deleteItem(root->val,root->right);
            return root;
        }
        
    }
    return root;
}

int main() {
    // create root node
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(11);
    root->right->right->left = new Node(13);
    root->right->right->right = new Node(15);

    //             8
    //           /   \
    //         4      12
    //       /  \    /  \
    //     2    6  10   14
    //    / \  / \ / \  / \
    //   1  3 5 7 9 11 13 15


    // Now the BST has 15 nodes and is balanced
    deleteItem(5,root);
    inorder(root);
    cout<<endl;
    deleteItem(3,root);
    
    inorder(root);
    cout<<endl;
    return 0;
}

