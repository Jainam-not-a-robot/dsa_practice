#include <bits/stdc++.h>
using namespace std;

// TreeNode definition (same as LeetCode)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return p == q;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right && p->val == q->val;
    }
};

int main() {
    // Create first tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create second tree (same structure and values)
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Create third tree (different)
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(3);

    Solution sol;

    cout << "Tree p and q are same? " 
         << (sol.isSameTree(p, q) ? "Yes" : "No") << endl;

    cout << "Tree p and r are same? " 
         << (sol.isSameTree(p, r) ? "Yes" : "No") << endl;

    return 0;
}
