#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    private:
        void helper(TreeNode* root, int& val)
        {
            if(!root) return;

            helper(root->right, val);

            root->val = root->val + val;
            val = root->val;

            helper(root->left, val);

            return;
        }
    public:
        TreeNode* convertBST(TreeNode* root) {

            int val = 0;
            helper(root, val);
            return root;
        }
    };