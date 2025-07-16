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

    private :
    
    void helper(TreeNode* root, string curr, int& sum)
    {
        if(!root) return;
        
        curr = curr + to_string(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + stoi(curr);
            return;
        }

        helper(root->left, curr, sum);
        helper(root->right, curr, sum);

        return;
    }
    public:
        int sumNumbers(TreeNode* root) {
            
            string curr;
            int sum = 0;
            helper(root, curr, sum);
            return sum;
        }
    };