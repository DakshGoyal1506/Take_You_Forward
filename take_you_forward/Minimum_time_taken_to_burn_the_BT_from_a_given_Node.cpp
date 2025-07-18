#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };

class Solution{

    private:

        TreeNode* find(TreeNode* root, int target)
        {
            if(!root) return root;
            if(root->val == target) return root;
            TreeNode* leftRes = find(root->left, target);
            if (leftRes) return leftRes;
            // if not found, search right
            return find(root->right, target);
        }

    public:
        int timeToBurnTree(TreeNode* root, int start){
            //your code goes here

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

            unordered_set<TreeNode*> visited;
            TreeNode* target = find(root, start);
            q.push(target);
            visited.insert(target);

            int currDistance = 0;

            while(!q.empty())
            {
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

            return currDistance - 1;
        }	
    };