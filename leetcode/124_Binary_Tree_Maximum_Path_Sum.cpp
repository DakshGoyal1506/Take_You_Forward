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
        int Helper(TreeNode* root, int& pathSum)
        {
            if(root == NULL) return 0;

            int rightPath = max(0, Helper(root->right, pathSum));
            int leftPath = max(0, Helper(root->left, pathSum));

            pathSum = max(pathSum, rightPath + leftPath + root->val);

            return max(rightPath, leftPath) + root->val;
        }
    public:
        int maxPathSum(TreeNode* root) {

            int pathSum = INT_MIN;

            Helper(root, pathSum);

            return pathSum;
            
        }
    };