#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {

            int total = nums[0];
            int maxSoFar = nums[0];
            int minSoFar = nums[0];
            int finalMax = nums[0];
            int finalMin = nums[0];
            int n = nums.size();

            for(int i = 1; i < n; i++)
            {
                total = total + nums[i];
                maxSoFar = nums[i] + max(maxSoFar, 0);
                finalMax = max(finalMax, maxSoFar);

                minSoFar = nums[i] + min(minSoFar, 0);
                finalMin = min(finalMin, minSoFar);
            }

            return finalMax < 0 ? finalMax : max(finalMax, total - finalMin);
            
        }
    };