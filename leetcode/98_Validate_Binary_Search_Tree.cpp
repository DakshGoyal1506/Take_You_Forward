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
        bool helper(TreeNode* root, long long& prev)
        {
            if(!root) return true;

            if(!helper(root->left, prev)) return false;

            if(prev >= root->val) return false;

            prev = root->val;

            return helper(root->right, prev);
        }
    public:
        bool isValidBST(TreeNode* root) {

            long long prev = LLONG_MIN;
            return helper(root, prev);
            
        }
    };

// class Solution {
    
//     public:
//         bool isValidBST(TreeNode* root) {

//             if(!root) return true;

//             if(root->right && root->right->val < root->val) return false;

//             if(root->left && root->left->val > root->val) return false;

//             return isValidBST(root->left) && isValidBST(root->right);
//         }
//     };