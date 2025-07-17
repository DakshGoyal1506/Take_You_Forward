#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
    };

class Solution{

    private:
        void helper(TreeNode* root, vector<int> curr, vector<vector<int>>& ans)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                curr.push_back(root->data);
                ans.push_back(curr);
                return;
            }

            curr.push_back(root->data);
            if(root->left) helper(root->left, curr, ans);
            if(root->right) helper(root->right, curr, ans);
        }
    public:
        vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here

            vector<vector<int>> ans;
            vector<int> curr;
            helper(root, curr, ans);
            return ans;
        }
};