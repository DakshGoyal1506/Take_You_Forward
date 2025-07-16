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
    public:
        vector<double> averageOfLevels(TreeNode* root) 
        {
            vector<double> ans;

            if(root == nullptr) return ans;

            queue<TreeNode*> q;
            q.push(root);
            q.push(nullptr);

            double sum = 0;
            int count = 0;

            while(!q.empty())
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr == nullptr)
                {
                    ans.push_back(sum / count);
                    sum = count = 0;
                    
                    if(q.empty()) break;
                    
                    q.push(curr);
                    continue;
                }
                sum = sum + curr->val;
                count++;

                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);

            }
            return ans;
        }
    };