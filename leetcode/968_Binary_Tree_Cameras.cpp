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

/*
0 = no camera coverage
1 = camera coverage
2 = camera
*/

class Solution {

    private:

        int cameras;

        int helper(TreeNode* node)
        {
            if(!node) return;

            int left = helper(node->left);
            int right = helper(node->right);

            if(left == 0 || right == 0)
            {
                cameras ++;
                return 2;
            }

            if(left == 2 || right == 2) return 1;

            return 0;
        }
    public:
        int minCameraCover(TreeNode* root) {

            cameras = 0;

            if(helper(root) == 0) cameras++;

            return cameras;
        }
    };