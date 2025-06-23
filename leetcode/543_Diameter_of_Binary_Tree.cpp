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
        int maxDepth(TreeNode* root, int& diameter) {

            if (root == NULL) return 0;

            int right_height = maxDepth(root->right, diameter);
            int left_height = maxDepth(root->left, diameter);

            diameter = max(diameter, right_height + left_height);

            return 1 + max(right_height , left_height);
            
        }
    public:
        int diameterOfBinaryTree(TreeNode* root) {

            int diameter = 0;
            maxDepth(root, diameter);
            return diameter;
            
        }
    };