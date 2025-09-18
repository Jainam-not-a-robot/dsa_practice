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

    

};
    void inorder_iterative(Node* root,vector<int>&ans){
        stack<Node* > s;
        Node* current=root;
        while(current!=NULL||!s.empty()){
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            ans.push_back(current->data);
            current=current->right;
        }
    }
int main() {
    // create root node
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    vector<int>ans;
    inorder_iterative(root,ans);
    for(auto &x:ans)cout<<x<<' ';
    cout<<endl;
    return 0;
}
