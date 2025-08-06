#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {

            int n = nums.size();
            sort(nums.begin(), nums.end());

            vector<int> parent(n, 0), dp(n, 1);
            int maxLen = 0;
            int lastIndex = 0;

            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
                for(int j = 0; j < i; j++)
                {
                    if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    {
                        parent[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }

                if(dp[i] > maxLen)
                {
                    maxLen = dp[i];
                    lastIndex = i;
                }
            }

            int i = lastIndex;
            vector<int> ans;

            while(parent[i] != i)
            {
                ans.push_back(nums[i]);
                i = parent[i];
            }
            ans.push_back(nums[i]);
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };