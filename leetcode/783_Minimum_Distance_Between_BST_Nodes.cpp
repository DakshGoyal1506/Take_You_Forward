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
        void helper(TreeNode* root, int& ans)
        {
            if(root->left == nullptr && root->right == nullptr) return ;

            int right = 0, left = 0;
            int val = root->val;

            if(root->left)
            {
                left = root->left->val;
                helper(root->left, ans);
            }
            if(root->right)
            {
                right = root->right->val;
                helper(root->right, ans);
            }

            ans = min({ans, val - left, abs(right - val)});
            return;
        }
    public:
        int minDiffInBST(TreeNode* root) {
            
            int ans = INT_MAX;  
            helper(root, ans);
            return ans;
        }
    };