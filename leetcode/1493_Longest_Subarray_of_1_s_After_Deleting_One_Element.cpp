#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zero = 0;
        int right = 0;
        int left = 0;
        int maxlen = 0;
        int n = nums.size();

        while(right < n)
        {
            if(nums[right] == 0)
            {
                zero++;
            }
            while(zero > 1)
            {
                if(nums[left] == 0) zero--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
            right ++;
        }
        maxlen = max(maxlen, right - left);
        
        return --maxlen;
    }
};