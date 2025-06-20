#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {

            return Helper(nums, k) - Helper(nums, k - 1);
            
        }
    
    private:
        int Helper(const vector<int>& nums, int k)
        {
            if(k <= 0) return 0;

            int left = 0, right = 0;
            int n = nums.size();
            unordered_map<int, int> mp;
            int distinct = 0;
            int res = 0;

            while(right < n)
            {
                if(mp[nums[right]] == 0)
                {
                    distinct++;
                }
                mp[nums[right]]++;

                while(distinct > k)
                {
                    mp[nums[left]]--;
                    if(mp[nums[left]] == 0) distinct --;
                    left++;
                }

                res = res + (right - left + 1);
                right++;            }

            return res;
        }
    };