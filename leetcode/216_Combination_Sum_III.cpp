#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {

            vector<vector<int>> ans;
            vector<int> ds;
            helper(1, 0, ds, ans, k, n);
            return ans;
            
        }
    
    private:

        void helper(int index, int sum, vector<int>& ds, vector<vector<int>>& ans, int k, int n)
        {
            if(ds.size() == k)
            {
                if(sum == n)
                {
                    ans.push_back(ds);
                }
                return;
            }

            for(int i = index; i <= 9; i++)
            {
                ds.push_back(i);
                helper(i + 1, sum + i, ds, ans, k, n);
                ds.pop_back();
            }
        }
    };