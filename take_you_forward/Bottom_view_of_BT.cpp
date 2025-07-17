#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
    };

class Solution {
    public:
        vector <int> bottomView(TreeNode *root){

            vector<int> ans;

            if(!root) return ans;

            queue<pair<TreeNode*, int>> q;
            map<int, int> mp;

            q.emplace(root, 0);

            while(!q.empty())
            {
                auto& x = q.front();
                q.pop();
                TreeNode* node = x.first;
                int col = x.second;

                mp[col] = node->data;

                if(node->left) q.emplace(node->left, col - 1);
                if(node->right) q.emplace(node->right, col + 1);
            }

            for(auto& x: mp)
            {
                ans.push_back(x.second);
            }
            return ans;
        }
    };