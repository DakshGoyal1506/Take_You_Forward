#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {

            int n = prices.size();

            vector<vector<int>> dp(n+1, vector<int>(2, 0));

            dp[n][0] = dp[n][1] = 0;

            for(int i = n - 1; i >= 0; i--)
            {
                for(int buy = 0; buy <= 1; buy++)
                {
                    /*
                    buy = 0 we do not have anyting
                    buy = 1 we have something, so we cannot buy more
                    */

                    if(buy == 0)
                    {
                        dp[i][buy] = max(0 + dp[i+1][0], (-1)*prices[i] + dp[i+1][1]);
                    }
                    else
                    {
                        dp[i][buy] = max(0 + dp[i + 1][1], prices[i] + dp[i+1][0]);
                    }
                }
            }
            return dp[0][0];
        }
    };