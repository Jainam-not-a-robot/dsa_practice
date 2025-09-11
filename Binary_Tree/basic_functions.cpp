#include <bits/stdc++.h>
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

    int height(Node* root) {
        if (root == NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int totalNodes(Node* root) {
        if (root == NULL) return 0;
        int leftNodes = totalNodes(root->left);
        int rightNodes = totalNodes(root->right);
        return leftNodes + rightNodes + 1;
    }

    void inorder(Node* root){
        if(root==NULL)return;
        inorder(root->left);
        cout<<root->data<<' ';//this line comes above for preorder and below for postorder
        inorder(root->right);
    }

    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                Node* newNode=q.front();
                q.pop();
                if(newNode->left!=NULL)q.push(newNode->left);
                if(newNode->right!=NULL)q.push(newNode->right);
                level.push_back(newNode->data);
            }
            ans.push_back(level);
        }
        return ans;
    }


};

int main() {
    // create root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Height of tree: " << root->height(root) << endl;
    cout << "Total nodes in tree: " << root->totalNodes(root) << endl;
    root->inorder(root);

    return 0;
}
