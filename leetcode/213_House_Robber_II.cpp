#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int helper(vector<int>& nums, int left, int right)
        {
            int prev = nums[left];
            int prev2 = 0;
            int curr = nums[left];
            left++;

            for(; left <= right; left++)
            {
                int pick = nums[left];

                if(left > 1) pick = pick + prev2;
                int nonpick = prev;

                curr = max(pick, nonpick);

                prev2 = prev;
                prev = curr;
            }
            return curr;
        }
    public:
        int rob(vector<int>& nums) {

            int n = nums.size();
            return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
        }
    };