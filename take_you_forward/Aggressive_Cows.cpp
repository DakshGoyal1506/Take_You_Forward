#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        bool helper(vector<int>& nums, int k, int mid)
        {
            int count = 1;
            int last = nums [0];

            for(int x : nums)
            {
                if(x - last >= mid)
                {
                    count++;
                    last = x;
                }

                if(count >= k) return true;
            }
            return false;
        }
    public:
        int aggressiveCows(vector<int> &nums, int k) {

            int n = nums.size();
            sort(nums.begin(), nums.end());
            
            int low = 1, high = nums[n - 1];

            while(low < high)
            {
                int mid = (low + high) / 2;

                if(helper(nums, k, mid)) low = mid + 1;
                else high = mid - 1;
            }

            return high;
        }
};