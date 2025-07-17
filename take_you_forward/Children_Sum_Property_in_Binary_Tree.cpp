#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };

class Solution {

    private:
        bool helper(TreeNode* root)
        {
            if(!root) return true;

            if(root->left == nullptr && root->right == nullptr) return true;

            int left = 0;
            if(root->left) left = root->left->val;

            int right = 0;
            if(root->right) right = root->right->val;

            if(root->val != left + right) return false;

            return helper(root->left) && helper(root->right);
        }
    public:
        int checkChildrenSum(TreeNode* root) {
            // Your code goes here
            return helper(root);
        }
    };  