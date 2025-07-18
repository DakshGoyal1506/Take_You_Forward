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
        TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp)
        {
            if(postStart > postEnd || inStart > inEnd) return nullptr;

            TreeNode* root = new TreeNode(postorder[postEnd]);

            int InRoot = mp[root->val];

            int num = InRoot - inStart;

            root->left = helper(postorder, postStart, postStart + num - 1, inorder, inStart, InRoot - 1, mp);

            root->right = helper(postorder, postStart + num, postEnd - 1, inorder, InRoot + 1, inEnd, mp);

            return root;
        }
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

            unordered_map<int, int> mp;

            int n = inorder.size();
            for(int i = 0; i < n; i++)
            {
                mp[inorder[i]]= i;
            }
            
            return helper(postorder, 0, n - 1, inorder, 0, n - 1, mp);
        }
    };