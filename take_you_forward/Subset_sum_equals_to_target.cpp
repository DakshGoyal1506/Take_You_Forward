#include<bits/stdc++.h>
using namespace std;

class Solution{   
    public:
        bool isSubsetSum(vector<int>arr, int target){

            int n = arr.size();
            vector<vector<bool>> dp(n, vector<bool>(target+1, false));

            for(int i = 0; i < n; i++) dp[i][0] = true;

            if(arr[0] <= target) dp[0][arr[0]] = true;

            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j <= target; j++)
                {
                    bool notPicked = dp[i - 1][j];

                    bool picked = false;

                    if(arr[i] <= j)
                    {
                        picked = dp[i - 1][j - arr[i]];
                    }

                    dp[i][j] = notPicked || picked;
                }
            }
            return dp[n - 1][target];
        }
    };