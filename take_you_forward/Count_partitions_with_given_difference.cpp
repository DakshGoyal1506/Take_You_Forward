#include <bits/stdc++.h>
using namespace std;

class Solution {

    int mod = (int)1e9 + 7;
  public:
    int countPartitions(int n, int diff, vector<int>& arr) {

        int sum = 0;
        for(int x : arr)
        {
            sum = sum + x;
        }

        int target = 0;

        if((sum - diff) < 0 || (sum - diff) % 2) return 0;
        else target = (sum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                int non = dp[i - 1][j];

                int pick = 0;
                if(arr[i] <= j) pick = dp[i - 1][j - arr[i]];

                dp[i][j] = (non + pick) % mod;
            }
        }
        return dp[n-1][target];
    }
};