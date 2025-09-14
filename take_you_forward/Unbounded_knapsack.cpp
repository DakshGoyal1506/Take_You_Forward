#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {

            vector<vector<int>> dp(n, vector<int>(W+1, 0));

            // initialize first row: we can take multiple copies of item 0
            for(int w = wt[0]; w <= W; w++)
            {
                dp[0][w] = (w / wt[0]) * val[0];
            }

            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j <= W; j++)
                {
                    int skip = dp[i-1][j];

                    int take = -1;
                    if(wt[i] <= j)
                    {
                        take = val[i] + dp[i][j - wt[i]];
                    }

                    dp[i][j] = max(skip, take);
                }
            }
            return dp[n-1][W];
        }
};
