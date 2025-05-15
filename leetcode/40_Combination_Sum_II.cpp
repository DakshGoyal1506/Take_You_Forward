#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> ds;
            findingSet(0, ds, ans, candidates, target);
            return ans;
        }
    
    private:
        void findingSet(int index, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates, int target)
        {
           if(target == 0)
           {
                ans.push_back(ds);
                return;
           }

           for(int i = index; i < candidates.size(); i++)
           {
                if(i > index && candidates[i] == candidates[i - 1]) continue;
                if(target < candidates[i]) break;

                ds.push_back(candidates[i]);
                findingSet(i + 1, ds, ans, candidates, target - candidates[i]);
                ds.pop_back();
           }
        }
    };