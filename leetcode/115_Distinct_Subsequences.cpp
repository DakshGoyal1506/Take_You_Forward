#include<bits/stdc++.h>
using namespace std;

class Solution {

    int mod = INT_MAX;
    public:
        int numDistinct(string s, string t) {

            int n = s.length();
            int m = t.length();

            vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

            for(int i = 0; i <= n; i++)
            {
                dp[i][0] = 1;
            }

            for(int i = 1; i <=n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(s[i - 1] == t[j - 1])
                    {
                        long long notTake = dp[i-1][j];
                        long long take = dp[i-1][j-1];
                        dp[i][j] = (notTake + take) % mod;
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }
            
            return dp[n][m];
        }
    };