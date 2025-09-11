#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 1;
        while (!q.empty()) {
            int size = q.size();
            long long lw = q.front().second;
            long long rw = q.back().second;
            width = max(width, rw - lw + 1);

            long long offset = q.front().second; // normalize indices
            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= offset; // normalize
                if (node->left) q.push({node->left, 2*idx + 1});
                if (node->right) q.push({node->right, 2*idx + 2});
            }
        }
        return width;
    }
};

int main() {
    /*
        Example tree:
                1
               / \
              3   2
             /     \
            5       9
           /         \
          6           7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    int maxWidth = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    return 0;
}
