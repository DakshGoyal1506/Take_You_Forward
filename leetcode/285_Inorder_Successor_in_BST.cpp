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

class Solution{

    private:
        void helper(TreeNode* root, vector<int>& sorted)
        {
            if(!root) return;

            helper(root->left, sorted);
            sorted.push_back(root->val);
            helper(root->right, sorted);
            return;
        }
	public:
		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here

            int suc = -1;
            int pred = -1;

            vector<int> arr;
            helper(root, arr);

            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i] < key) pred = arr[i];
                else if(arr[i] > key)
                {
                    suc = arr[i];
                    break;
                }
            }

            return {pred, suc};
		}
};