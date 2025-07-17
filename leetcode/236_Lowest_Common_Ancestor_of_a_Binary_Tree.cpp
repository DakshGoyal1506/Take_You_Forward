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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            if(root == NULL || root == p || root == q) return root;

            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);

            if(left == NULL) return right;
            else if(right == nullptr) return left;
            else return root;
            
        }
    };

// class Solution {

//     private:
//         void helper(TreeNode* root, unordered_map<int, TreeNode*>& mp, TreeNode* parent)
//         {
//             if(!root) return;

//             mp[root->val] = parent;

//             if(root->left) helper(root->left, mp, root);
//             if(root->right) helper(root->right, mp, root);
//         }
//     public:
//         TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

//             unordered_map<int, TreeNode*> mp;
//             helper(root, mp, nullptr);

//             TreeNode* a = p;
//             TreeNode* b = q;

//             while(a != b)
//             {
//                 a = a == NULL ? q : mp[a->val];
//                 b = b == NULL ? p : mp[b->val];
//             }
//             return a;
//         }
//     };