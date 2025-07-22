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

    int ans = 0;

    // returns (bestSum, isBST, subtreeMin, subtreeMax)
    tuple<int,bool,int,int> dfs(TreeNode* node) {
        if (!node) {
            // empty tree is a BST of sum=0, with extreme min/max
            return {0, true, INT_MAX, INT_MIN};
        }
        auto [lsum, lbst, lmin, lmax] = dfs(node->left);
        auto [rsum, rbst, rmin, rmax] = dfs(node->right);

        // can we treat this as a BST?
        if (lbst && rbst && node->val > lmax && node->val < rmin) {
            int sum = lsum + rsum + node->val;
            ans = max(ans, sum);
            int mn  = std::min<int>(lmin, node->val);
            int mx  = std::max<int>(rmax, node->val);
            return { sum, true, mn, mx };
        }
        // otherwise discard this subtree, return best from children
        return {0, false, 0, 0 };
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// class Solution {

//     private:
//         tuple<int, bool, int, int> helper(TreeNode* root, int minValue, int maxValue)
//         {
//             if(!root) return make_tuple(0, true, INT_MIN, INT_MAX);

//             auto [leftSize, isLeftBST, leftMin, leftMax] = helper(root->left, minValue, root->val);
//             auto [rightSize, isRightBST, rightMin, rightMax] = helper(root->right, root->val, maxValue);

//             if(isLeftBST && isRightBST && leftMax < root->val && root->val < rightMax)
//             {
//                 return make_tuple(leftSize + rightSize + root->val, true, min(root->val, leftMin), max(root->val, rightMax));
//             }
//             else return make_tuple(max(leftSize, rightSize), false, INT_MIN, INT_MAX);
//         }
//     public:
//         int maxSumBST(TreeNode* root) {

//             return get<0>(helper(root, INT_MIN, INT_MAX));
            
//         }
//     };