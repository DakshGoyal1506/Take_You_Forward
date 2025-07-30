#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minInsertions(string s) {

            string t = s;
            reverse(t.begin(), t.end());

            int n = s.size();

            vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(s[i-1] == t[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            int longest = dp[n][n];

            return n - longest;
            
        }
    };

// class Solution {
//     public:
//         int minInsertions(string s) {

//             unordered_map<char, int> mp;

//             for(char c : s)
//             {
//                 mp[c]++;
//             }

//             int count = 0;

//             for(auto& x : mp)
//             {
//                 if(x.second % 2 == 1) count++;
//             }
//             return count - 1;
//         }
//     };