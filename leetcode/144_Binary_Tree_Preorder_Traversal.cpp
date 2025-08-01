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
    public:
        vector<int> preorderTraversal(TreeNode* root) {

            vector<int> ans;
            Helper(root, ans);
            return ans;
        }

        void Helper(TreeNode* root, vector<int>& ans)
        {
            if(root == NULL) return;
            ans.push_back(root->val);
            Helper(root->left, ans);
            Helper(root->right, ans);
        }
    };