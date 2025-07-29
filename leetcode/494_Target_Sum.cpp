#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {

            int n = nums.size();
            int sum = 0;

            for(int x : nums)
            {
                sum = sum + x;
            }
            
            if((sum - target) < 0 || (sum - target) % 2) return 0;
            int tar = (sum - target) / 2;

            vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

            if(nums[0] == 0) dp[0][0] = 2;
            else dp[0][0] = 1;

            if(nums[0] != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;

            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j <= tar; j++)
                {
                    int non = dp[i - 1][j];

                    int take = 0;
                    if(nums[i] <= j) take = dp[i - 1][j - nums[i]];
                    dp[i][j] = non + take;
                }
            }
            return dp[n - 1][tar];
        }
    };