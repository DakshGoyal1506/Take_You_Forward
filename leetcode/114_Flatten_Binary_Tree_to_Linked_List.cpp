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
        void flatten(TreeNode* root) {

            while(root)
            {
                if(root->left)
                {
                    TreeNode* rightMost = root->left;
                    while(rightMost->right)
                    {
                        rightMost = rightMost->right;
                    }

                    rightMost->right = root->right;
                    root->right = root->left;
                    root->left = nullptr;
                }
                root = root->right;
            }
            
        }
    };