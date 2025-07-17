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
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

            unordered_map<TreeNode*, TreeNode*> mp;
            queue<TreeNode*> q;

            q.push(root);

            while(!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }

            vector<int> ans;
            unordered_set<TreeNode*> visited;
            q.push(target);
            visited.insert(target);
            int currDistance = 0;

            while(!q.empty())
            {
                if(currDistance == k)
                {
                    while(!q.empty())
                    {
                        ans.push_back(q.front()->val);
                        q.pop();
                    }
                    return ans;
                }

                int n = q.size();

                for(int i = 0; i < n; i++)
                {

                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left && visited.find(node->left) == visited.end())
                    {
                        q.push(node->left);
                        visited.insert(node->left);
                    }

                    if(node->right && visited.find(node->right) == visited.end())
                    {
                        q.push(node->right);
                        visited.insert(node->right);
                    }

                    if(mp.find(node) != mp.end() && visited.find(mp[node]) == visited.end())
                    {
                        q.push(mp[node]);
                        visited.insert(mp[node]);
                    }
                }
                currDistance++;
            }
            return ans;
        }
    };