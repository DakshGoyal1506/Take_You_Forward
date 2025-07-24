#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int helper(int index, vector<int>& nums, vector<int>& dp)
        {
            if(index == 0) return nums[0];
            if(index < 0) return 0;

            if(dp[index] != -1) return dp[index];

            int consider = nums[index] + helper(index - 2, nums, dp);
            int notCon = helper(index - 1, nums, dp);

            dp[index] = max(consider, notCon);

            return dp[index];
        }
    public:
        int rob(vector<int>& nums) {

            int n = nums.size();
            vector<int> dp(n, -1);

            return helper(n - 1, nums, dp);
        }
    };