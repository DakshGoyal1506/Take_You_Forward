#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums) {

            int maxNum = *max_element(nums.begin(), nums.end());

            int ans = 0, count = 0;

            for(int x : nums)
            {
                if(x == maxNum) count++;
                else
                {
                    ans = max(ans, count);
                    count = 0;
                }
            }
            ans = max(ans, count);
            return ans;
        }
    };