#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int ninjaTraining(vector<vector<int>>& matrix) {

            int n = matrix.size();

            vector<vector<int>> dp(n, vector<int>(4, 0));

            dp[0][0] = max(matrix[0][1], matrix[0][2]);
            dp[0][1] = max(matrix[0][0], matrix[0][2]);
            dp[0][2] = max(matrix[0][1], matrix[0][0]);
            dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        if(j != k)
                        {
                            int x = matrix[i][k] + dp[i - 1][k];
                            dp[i][j] = max(dp[i][j], x);
                        }
                    }
                }
                dp[i][3] = max({dp[i][0], dp[i][1], dp[i][2]});
            }
            return dp[n - 1][3];
        }
    };