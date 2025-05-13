#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            findingSet(0, ds, 0, ans, candidates, target);
            return ans;
        }
    
    private:
        void findingSet(int index, vector<int>& ds, int sum, vector<vector<int>>& ans, vector<int>& candidates, int target)
        {
            if(sum > target) return;
            if(index == candidates.size())
            {
                if(sum == target)
                {
                    ans.push_back(ds);
                }
                return;
            }

            sum = sum + candidates[index];
            ds.push_back(candidates[index]);
            findingSet(index + 1, ds, sum, ans, candidates, target);

            sum = sum - candidates[index];
            ds.pop_back();
            findingSet(index + 1, ds, sum, ans, candidates, target);
        }
    };