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
        void helper(TreeNode* root, vector<int>& ans, int& curr, int& maxCount, TreeNode*& prev)
        {
            if(root == nullptr) return;

            helper(root->left, ans, curr, maxCount, prev);

            if(prev != nullptr && root->val == prev->val) curr++;
            else curr = 1;

            if(curr > maxCount)
            {
                ans.clear();
                maxCount = curr;
                ans.push_back(root->val);
            }
            else if(curr == maxCount) ans.push_back(root->val);

            prev = root;

            helper(root->right, ans, curr, maxCount, prev);

        }
    public:
        vector<int> findMode(TreeNode* root) {

            vector<int> ans;
            int curr = 0;
            int maxCount = 0;
            TreeNode* prev = nullptr;

            helper(root, ans, curr, maxCount, prev);

            return ans;
        }
    };