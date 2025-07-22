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
        void helper(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& mid, TreeNode*& last)
        {
            if(root == nullptr) return;

            helper(root->left, prev, first, mid, last);

            if(prev && prev->val > root->val)
            {
                if(!first)
                {
                    first = prev;
                    mid = root;
                }
                else
                {
                    last = root;
                }
            }
            prev = root;

            helper(root->right, prev, first, mid, last);
        }
    public:
        void recoverTree(TreeNode* root) {

            TreeNode* prev = nullptr, *first = nullptr, *mid = nullptr, *last = nullptr;

            helper(root, prev, first, mid, last);

            if(first && last)
            {
                swap(first->val, last->val);
            }
            else if(first, mid)
            {
                swap(first->val, mid->val);
            }
            
        }
    };