#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {

            int n = nums.size();

            for(int i = 0; i < n; i++)
            {
                nums[i] = nums[i] % 2;
            }

            return Helper(nums, k) - Helper(nums, k - 1);
            
        }
    
    private:
        int Helper(vector<int>& nums, int k)
        {
            if (k < 0) return 0;

            int left = 0, right = 0;
            int count = 0;
            int sum = 0;
            int n = nums.size();

            while(right < n)
            {
                sum = sum + nums[right];

                while(sum > k)
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