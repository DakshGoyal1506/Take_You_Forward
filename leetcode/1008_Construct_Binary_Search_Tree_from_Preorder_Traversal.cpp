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
        TreeNode* helper(vector<int>& preorder, int start, int end)
        {
            if(end < start) return nullptr;

            TreeNode* root = new TreeNode(preorder[start]);

            int val = root->val;
            int mid = start + 1;

            while(mid <= end && preorder[mid] < val) mid++;

            root->left = helper(preorder, start+1, mid-1);
            root->right = helper(preorder, mid, end);

            return root;
        }
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder) {

            int n = preorder.size();

            return helper(preorder, 0, n - 1);
            
        }
    };