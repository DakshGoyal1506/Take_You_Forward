#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
    };

class Solution{
    public:
        vector<int> topView(TreeNode *root){

            vector<int> ans;

            if(!root) return ans;
            queue<pair<TreeNode*, int>> q;
            map<int, int> mp;

            q.push({root, 0});

            while(!q.empty())
            {
                auto& x = q.front();
                q.pop();
                TreeNode* node = x.first;
                int col = x.second;

                if(mp.find(col) == mp.end()) mp[col] = node->data;

                if(node->left) q.emplace(node->left, col - 1);
                if(node->right) q.emplace(node->right, col + 1);
            }

            for(auto x : mp)
            {
                ans.push_back(x.second);
            }
            return ans;
        }
};

// class Solution{

//     private:
//         void helper(TreeNode* root, int col, map<int, vector<int>>& mp)
//         {
//             if(!root) return;

//             mp[col].push_back(root->data);

//             if(root->left) helper(root->left, col - 1, mp);
//             if(root->right) helper(root->right, col + 1, mp);
//         }
//     public:
//         vector<int> topView(TreeNode *root){
//             //your code goes here
//             map<int, vector<int>> mp;
//             helper(root, 0, mp);

//             vector<int> ans;

//             for(auto x: mp)
//             {
//                 vector<int> temp = x.second;
//                 ans.push_back(temp[0]);
//             }
//             return ans;
//         }
// };