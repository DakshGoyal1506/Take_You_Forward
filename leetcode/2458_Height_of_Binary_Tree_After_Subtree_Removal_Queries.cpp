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
    int n;
    vector<int> D;          // depth[v]
    vector<int> subMax;     // max depth in subtree v
    vector<int> upMax;      // max depth outside subtree v
    unordered_map<int,TreeNode*> mp;  // value→node*

    void dfs1(TreeNode* node, TreeNode* parent, int d) {
        int v = node->val;
        mp[v] = node;
        D[v] = d;
        subMax[v] = d;  // at least itself
        if (node->left) {
            dfs1(node->left, node, d+1);
            subMax[v] = max(subMax[v], subMax[ node->left->val ]);
        }
        if (node->right) {
            dfs1(node->right, node, d+1);
            subMax[v] = max(subMax[v], subMax[ node->right->val ]);
        }
    }

    void dfs2(TreeNode* node) {
        int v = node->val;

        // find top two subtree‐max depths among children
        int best1 = -1, best2 = -1, c1 = -1, c2 = -1;
        auto consider = [&](TreeNode* ch){
            int w = ch->val, h = subMax[w];
            if (h > best1) { best2 = best1; c2 = c1; best1 = h; c1 = w; }
            else if (h > best2) { best2 = h; c2 = w; }
        };
        if (node->left)  consider(node->left);
        if (node->right) consider(node->right);

        // propagate upMax to each child
        auto process = [&](TreeNode* ch){
            int w = ch->val;
            // sibling’s subMax
            int sibMax = (w == c1 ? best2 : best1);
            // upMax[w] is max of:
            // 1) upMax[v]    (outside v’s subtree)
            // 2) D[v]        (just v itself)
            // 3) sibMax      (best from the other child)
            upMax[w] = max({ upMax[v], D[v], sibMax });
            dfs2(ch);
        };
        if (node->left)  process(node->left);
        if (node->right) process(node->right);
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        if (!root) return {};

        // The values are 1..n, but we don't know n up‐front
        // First pass to count nodes:
        function<int(TreeNode*)> cnt = [&](TreeNode* u){
            if(!u) return 0;
            return 1 + cnt(u->left) + cnt(u->right);
        };
        n = cnt(root);

        D.resize(n+1);
        subMax.resize(n+1);
        upMax.resize(n+1);

        // 1) DFS1: fill D[] and subMax[]
        dfs1(root, nullptr, 0);

        // 2) DFS2: fill upMax[]
        // root has no “outside” so upMax[root]=0
        upMax[root->val] = 0;
        dfs2(root);

        // 3) Answer queries in O(1)
        vector<int> answer;
        answer.reserve(queries.size());
        for (int q : queries) {
            // height after removing subtree q
            answer.push_back(upMax[q]);
        }
        return answer;
    }
};