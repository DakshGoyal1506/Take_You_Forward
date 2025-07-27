#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumMedianSum(vector<int>& nums) {

            sort(nums.begin(), nums.end());
            int n = nums.size();
            int k = n / 3;
            long long ans = 0;

            for(int i = k; i < n; i = i + 2)
            {
                ans = ans + nums[i];
            }
            return ans;
        }
    };