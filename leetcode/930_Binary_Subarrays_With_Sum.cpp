#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {

            return Helper(nums, goal) - Helper(nums, goal - 1);
        }
    
    private:
        int Helper(vector<int>& nums, int goal) {

            if (goal < 0) return 0;

            int n = nums.size();
            int left = 0, right = 0;
            int count = 0;
            int sum = 0;

            while(right < n)
            {
                sum = sum + nums[right];
                
                while(sum > goal)
                {
                    sum = sum - nums[left];
                    left++;
                }
                
                count = count + (right - left + 1);
                
                right++;
            }

            return count;
        }
    };