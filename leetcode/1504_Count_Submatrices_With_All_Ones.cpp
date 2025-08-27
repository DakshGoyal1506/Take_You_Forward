#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // dp[i][j] = number of consecutive 1s ending at (i,j) horizontally
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j]) dp[i][j] = (j > 0 ? dp[i][j - 1] : 0) + 1;
                else dp[i][j] = 0;

                // count submatrices with bottom-right corner at (i,j)
                int minWidth = dp[i][j];
                for (int k = i; k >= 0 && minWidth > 0; --k) {
                    minWidth = min(minWidth, dp[k][j]);
                    ans += minWidth;
                }
            }
        }

        return ans;
    }
};