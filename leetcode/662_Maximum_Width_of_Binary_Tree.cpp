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
        int widthOfBinaryTree(TreeNode* root) {

            if(!root) return 0;
            using ull = unsigned long long;

            int ans = 0;

            queue<pair<TreeNode*, ull>> q;
            q.emplace(root, 0);

            while(!q.empty())
            {
                int n = q.size();
                int startIndex = q.front().second;
                int first = 0, last = 0;

                for(int i = 0; i < n; i++)
                {
                    TreeNode* node = q.front().first;
                    int index = q.front().second - startIndex;
                    q.pop();

                    if(i == 0) first = index;
                    if(i == n - 1) last = index;

                    if(node->left) q.emplace(node->left, 2ULL*index + 1);
                    if(node->right) q.emplace(node->right, 2ULL*index + 2);
                }

                ans = max<int>(ans, last - first + 1);
            }
            return ans;
        }
    };