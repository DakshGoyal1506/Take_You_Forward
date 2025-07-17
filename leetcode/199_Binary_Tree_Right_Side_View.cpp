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

class Solution{
    public:
        vector<int> rightSideView(TreeNode *root){

            vector<int> ans;

            if(!root) return ans;
            queue<pair<TreeNode*, int>> q;
            map<int, int> mp;

            q.push({root, 0});

            while(!q.empty())
            {
                auto& x = q.front();
                TreeNode* node = x.first;
                int row = x.second;
                q.pop();

                if(mp.find(row) == mp.end()) mp[row] = node->val;

                if(node->right) q.emplace(node->right, row + 1);
                if(node->left) q.emplace(node->left, row + 1);
            }

            for(auto x : mp)
            {
                ans.push_back(x.second);
            }
            return ans;
        }
};