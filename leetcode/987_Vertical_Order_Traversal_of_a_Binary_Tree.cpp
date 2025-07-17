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
        void helper(TreeNode* root, int row, int col, map<int, vector<pair<int,int>>>& mp)
        {
            if(!root) return;

            mp[col].emplace_back(row, root->val);

            if(root->left) helper(root->left, row + 1, col - 1, mp);
            if(root->right) helper(root->right, row + 1, col + 1, mp);
        }
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {

            map<int, vector<pair<int,int>>> mp;
            helper(root, 0, 0, mp);

            vector<vector<int>> ans;
            
            for(auto& x : mp)
            {
                auto& vec = x.second;

                sort(vec.begin(), vec.end(), [](auto& a, auto& b){
                    if(a.first != b.first) return a.first < b.first;
                    else return a.second < b.second;
                });

                vector<int> temp;
                for(auto &y: vec) temp.push_back(y.second);
                ans.push_back(temp);
            }
            return ans;
        }
    };