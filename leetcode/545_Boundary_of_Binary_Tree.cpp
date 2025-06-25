#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
        bool isLeaf(TreeNode* root)
        {
            return !root->left && !root->right;
        }

        void addLeftBoundary(TreeNode* root, vector<int>& ans)
        {
            TreeNode* curr = root->left;

            while(curr)
            {
                if(!isLeaf(curr)) ans.push_back(curr->val);

                if(curr->left) curr = curr->left;
                else curr = curr -> right;
            }
        }

        void addRightBoundary(TreeNode* root, vector<int>& ans)
        {
            TreeNode* curr = root->right;
            vector<int> temp;

            while(curr)
            {
                if(!isLeaf(curr)) temp.push_back(curr->val);

                if(curr->right) curr = curr->right;
                else curr = curr -> left;
            }

            for(int i = temp.size() - 1; i >= 0; i--)
            {
                ans.push_back(temp[i]);
            }
        }

        void addLeafNodes(TreeNode* root, vector<int>& ans)
        {
            if(isLeaf(root)) 
            {
                ans.push_back(root->val);
                return ;
            }
            if(root->left) addLeafNodes(root->left, ans);
            if(root->right) addLeafNodes(root->right, ans);
        }
    public:
        vector <int> boundary(TreeNode* root){
            //your code goes here

            vector<int> ans;
            if(root == NULL) return ans;

            ans.push_back(root->val);
            if(isLeaf(root)) 
            {
                return ans;
            }

            addLeftBoundary(root, ans);
            addLeafNodes(root, ans);
            addRightBoundary(root, ans);

            return ans;
        }
    };