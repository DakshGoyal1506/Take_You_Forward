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
        TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp)
        {
            if(preStart > preEnd || inStart > inEnd) return nullptr;

            TreeNode* root = new TreeNode(preorder[preStart]);

            int InRoot = mp[root->val];

            int num = InRoot - inStart;

            root->left = helper(preorder, preStart + 1, preStart + num, inorder, inStart, InRoot - 1, mp);

            root->right = helper(preorder, preStart + 1 + num, preEnd, inorder, InRoot + 1, inEnd, mp);

            return root;
        }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

            unordered_map<int, int> mp;

            int n = inorder.size();
            for(int i = 0; i < n; i++)
            {
                mp[inorder[i]]= i;
            }
            
            return helper(preorder, 0, n - 1, inorder, 0, n - 1, mp);
        }
    };