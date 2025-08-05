#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int helper(int index, int prev, vector<vector<int>>& dp, vector<int>& nums)
        {
            if(index == nums.size() - 1)
            {
                if(prev == -1 || nums[index] > nums[prev]) return 1;
                return 0;
            }

            if(dp[index][prev + 1] != -1) return dp[index][prev + 1];

            int non = helper(index + 1, prev, dp, nums);
            int take = 0;

            if(prev == -1) take = helper(index + 1, index, dp, nums) + 1;
            else if(nums[index] > nums[prev]) take = helper(index + 1, index, dp, nums) + 1;

            return dp[index][prev+1] = max(take, non);
        }
    public:
        int lengthOfLIS(vector<int>& nums) {

            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n+1, -1));

            return helper(0, -1, dp, nums);
            
        }
    };