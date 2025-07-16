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
        void helper(TreeNode* root, vector<int>& arr, int target, int& count)
        {
            if(!root) return;

            arr.push_back(root->val);
            
            long long sum = 0;

            for(int i = arr.size() - 1; i >= 0; i--)
            {
                sum = sum + arr[i];

                if(sum == target) count++;
            }

            helper(root->left, arr, target, count);
            helper(root->right, arr, target, count);

            arr.pop_back();
        }
    public:
        int pathSum(TreeNode* root, int targetSum) {

            vector<int> arr;
            int count = 0;

            helper(root, arr, targetSum, count);

            return count;
        }
    };