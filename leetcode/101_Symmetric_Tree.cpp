#include<bits/stdc++.h>
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
        bool helper(TreeNode* p, TreeNode* q)
        {
            if(p == NULL && q == NULL) return true;
            if(p == NULL || q == NULL) return false;

            if(p->val != q->val) return false;

            return helper(p->right, q->left) && helper(p->left, q->right);
        }
    public:
        bool isSymmetric(TreeNode* root) {

            return helper(root->left, root->right);
            
        }
    };