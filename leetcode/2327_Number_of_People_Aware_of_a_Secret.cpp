#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         int peopleAwareOfSecret(int n, int delay, int forget) {

//             vector<int> dp(n+1);
//             dp[1] = 1;

//             int share = 0, mod = 1e9 + 7;

//             for(int i = 2; i <= n; i++)
//             {
//                 dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)]+ mod) % mod;
//             }

//             int res = 0;

//             for(int i = n - forget + 1; i <= n; i++)
//             {
//                 res = (res + dp[i]) % mod;
//             }
//             return res;
//         }
//     };

class Solution {
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int MOD = 1e9+7;
            vector<int> dp(n+1);
            dp[1] = 1;
            
            long long share = 0;      // sum of dp[j] for j in [i-forget+1 .. i-delay]
            
            for(int i = 2; i <= n; i++){
                // once day i ≥ delay+1 we start adding dp[i-delay]
                if (i - delay >= 1) {
                    share = (share + dp[i - delay]) % MOD;
                }
                // once day i ≥ forget+1 we stop counting dp[i-forget]
                if (i - forget >= 1) {
                    share = (share - dp[i - forget] + MOD) % MOD;
                }
                dp[i] = (int)share;
            }
            
            // all who learned in the last 'forget' days still remember
            long long ans = 0;
            for(int i = n - forget + 1; i <= n; i++){
                ans = (ans + dp[i]) % MOD;
            }
            return (int)ans;
        }
    };