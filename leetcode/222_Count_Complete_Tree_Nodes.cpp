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
        int helper(TreeNode* root)
        {
            if(!root) return 0;

            return helper(root->left) + helper(root->right) + 1;
        }
    public:
        int countNodes(TreeNode* root) {
            return helper(root);
        }
    };