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

    // private:
    //     void helper(TreeNode* root, int target, unordered_set<int>& st)
    //     {
    //         if(root == NULL) return ;
    //         st.insert(root->val);

    //         if(root->val == target) return;

    //         if(root->left) helper(root->left, target, st);
    //         if(root->right) helper(root->right, target, st);
    //         return;
    //     }
    public:
        int rangeSumBST(TreeNode* root, int low, int high) {

            if(root == nullptr) return 0;

            if(root->val < low) return rangeSumBST(root->right, low, high);
            else if(root->val > high) return rangeSumBST(root->left, low, high);

            int left = rangeSumBST(root->left, low, high);
            int right = rangeSumBST(root->right, low, high);
            
            return left + right + root->val;
        }
    };