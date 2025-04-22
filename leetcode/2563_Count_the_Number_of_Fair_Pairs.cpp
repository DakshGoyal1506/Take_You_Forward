#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {

            long long count = 0;
            sort(nums.begin(), nums.end());

            int n = nums.size();

            for(int i = 0; i < n - 1; i++)
            {
                int lower_value = lower - nums[i];
                int upper_value = upper - nums[i];

                auto low_index = lower_bound(nums.begin() + i + 1, nums.end(), lower_value);
                auto upper_index = upper_bound(nums.begin() + i + 1, nums.end(), upper_value);

                count = count + (upper_index - low_index);                
            }

            return count;
            
        }
    };