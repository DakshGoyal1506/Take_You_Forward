#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
        int maxDepth(TreeNode* root) {

            if (root == NULL) return 0;

            int right = maxDepth(root->right);
            if(right == -1) return -1;

            int left = maxDepth(root->left);
            if(left == -1) return -1;
            
            if(abs(right - left) > 1) return -1;

            return max(right, left) + 1;
            
        }
    public:
        bool isBalanced(TreeNode* root) {

            int ans = maxDepth(root);

            if(ans == -1) return false;

            return true;
        }
    };