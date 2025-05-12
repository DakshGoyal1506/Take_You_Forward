#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {

            vector<vector<int>> ans = {{}};
            dfs(0, ans, nums);
            return ans;
            
        }

    private:
        
        void dfs(int index, vector<vector<int>>& ans, vector<int>& nums)
        {
            if(index == nums.size())
            {
                return;
            }

            vector<vector<int>> ans1 = ans;

            for(auto& s : ans1)
            {
                s.push_back(nums[index]);
            }

            ans.insert(ans.end(), ans1.begin(), ans1.end());

            dfs(index + 1, ans, nums);
        }
    };