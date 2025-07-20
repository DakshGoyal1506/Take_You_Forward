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
    public:
        TreeNode* trimBST(TreeNode* root, int low, int high) {

            if(!root) return root;

            TreeNode* left = trimBST(root->left, low, high);
            TreeNode* right = trimBST(root->right, low, high);

            if(root->val >= low && root->val <= high)
            {
                root->left = left;
                root->right = right;
                return root;
            }

            if(root->val < low) return right;
            // if(root->val > high) return left;
            else return left;
            
        }
    };