#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+1, 0);
        dp[0] = 1;                       // one way to make 0

        for (int c : coins) {
            for (int j = c; j <= amount; ++j) {
                long long sum = (long long)dp[j] + dp[j - c];
                dp[j] = sum > INT_MAX ? INT_MAX : int(sum);
            }
        }
        return int(dp[amount]);
    }
};

// class Solution {
//     public:
//         int change(int amount, vector<int>& coins) {

//             int n = coins.size();
//             vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

//             for(int i = 0; i <= amount; i++)
//             {
//                 if(i % coins[0] == 0) dp[0][i] = 1;
//                 else dp[0][i] = 0;
//             }
            
//             for(int i = 1; i < n; i++)
//             {
//                 for(int j = 0; j <= amount; j++)
//                 {
//                     long long non = dp[i - 1][j];
//                     long long take = 0;

//                     if(coins[i] <= j) take = dp[i][j - coins[i]];

//                     dp[i][j] = non + take;
//                 }
//             }

//             return int(dp[n - 1][amount]);
            
//         }
//     };