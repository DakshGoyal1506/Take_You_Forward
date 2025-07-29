#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> smallestSubarrays(vector<int>& nums) {

            int n = nums.size();
            vector<int> suffixBits(n);

            suffixBits[n-1] = nums[n-1];
            for(int i = n - 2; i >= 0; i--)
            {
                suffixBits[i] = suffixBits[i+1] | nums[i];
            }

            int B = 31;
            vector<int> bitsCovered(B, n);
            vector<int> ans(n);

            for(int i = n - 1; i >= 0; i--)
            {
                for(int b = 0; b < B; b++)
                {
                    if(nums[i] & (1<<b)) bitsCovered[b] = i;
                }

                int far = i;
                for(int b = 0; b < B; b++)
                {
                    if(suffixBits[i] & (1<<b)) far = max(far, bitsCovered[b]);
                }
                ans[i] = far - i + 1;
            }
            return ans;
        }
    };