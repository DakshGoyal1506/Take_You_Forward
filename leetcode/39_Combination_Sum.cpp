#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

            vector<vector<int>> ans;
            vector<int> ds;
            dfs(0, ds, ans, candidates, target);
            return ans;
        }
    
    private:
        void dfs(int index, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates, int target)
        {
            if (index == candidates.size()) 
            {
                if(target == 0)
                {
                    ans.push_back(ds);
                }
                return;
            }

            if(candidates[index] <= target)
            {
                ds.push_back(candidates[index]);
                dfs(index, ds, ans, candidates, target - candidates[index]);
                ds.pop_back();
            }

            dfs(index + 1, ds, ans, candidates, target);

            return ;
        }
    };