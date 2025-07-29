#include <bits/stdc++.h>
using namespace std;

class Solution{

    int mod = 1e9+7;
	public:
	int perfectSum(vector<int>&arr, int K){

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K+1, 0));

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        if(arr[0] <= K) dp[0][arr[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= K; j++)
            {
                int non = dp[i - 1][j];
                int taken = 0;
                if(arr[i] <= j) taken = dp[i - 1][j - arr[i]];

                dp[i][j] = (non + taken)%mod;
            }
        }
        return dp[n - 1][K];
	}
};