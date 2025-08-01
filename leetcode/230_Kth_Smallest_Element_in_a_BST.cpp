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
        void helper(TreeNode* root, int& k, int& ans)
        {
            if(root == nullptr) return;

            helper(root->left, k, ans);

            k--;
            if(k == 0)
            {
                ans = root->val;
                return;
            }

            helper(root->right, k, ans);
        }
    public:
        int kthSmallest(TreeNode* root, int k) {

            int ans = -1;
            helper(root, k, ans);
            return ans;
        }
    };