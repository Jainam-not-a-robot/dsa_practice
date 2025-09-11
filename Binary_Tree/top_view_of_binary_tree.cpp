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
    void topView(Node* root){
        deque<Node*>ans;
        ans.push_back(root);
        queue<pair<Node*,int>>q;
        q.push({root,0});
        int min_num=0,max_num=0;
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* newNode=q.front().first;
                int val=q.front().second;
                if(val<min_num)ans.push_front(newNode);
                if(val>max_num)ans.push_back(newNode);
                min_num=min(min_num,val);
                max_num=max(max_num,val);
                q.pop();
                if(newNode->left!=NULL)q.push({newNode->left,val-1});
                if(newNode->right!=NULL)q.push({newNode->right,val+1});
                
            }
            
        }
        for(auto x:ans)cout<<x->data<<' ';
        return;
    }


};

int main() {
    // Example tree:
    /*
            1
           / \
          2   3
           \
            4
             \
              5
               \
                6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right=new Node(6);
    root->right->right = new Node(5);
    root->right->right->left=new Node(7);
    // root->left->right->right->right = new Node(6);

    root->topView(root);

    return 0;
}//Instead we can also use map approach, lekin apna logic to apna logic hi hota hai :)