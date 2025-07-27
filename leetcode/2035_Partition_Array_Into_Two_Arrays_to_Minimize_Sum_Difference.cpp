#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
        int minimumDifference(vector<int>& nums) {

            int sum = 0;
            for(int x : nums) sum = sum + x;

            int n = nums.size();
            vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

            for(int i = 0; i < n; i++) dp[i][0] = true;

            if(nums[0] <= sum) dp[0][sum] = true;

            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j <= sum; j++)
                {
                    bool notPicked = dp[i - 1][j];

                    bool picked = false;

                    if(nums[i] <= j)
                    {
                        picked = dp[i - 1][j - nums[i]];
                    }

                    dp[i][j] = notPicked || picked;
                }
            }

            int ans = INT_MAX;

            for(int i = 0; i <= sum; i++)
            {
                if(dp[n-1][i] == true)
                {
                    int diff = abs(i - (sum - i));
                    ans = min(ans, diff);
                }
            }
            return ans;
        }
    };