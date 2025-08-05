#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minRemoval(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int left = 0, maxBalanced = 0;

            for (int right = 0; right < n; right++) {
                while ((long long)nums[right] > (long long)nums[left] * k) {
                    left++;
                }
                maxBalanced = max(maxBalanced, right - left + 1);
            }

            return n - maxBalanced; // Minimum removals = total elements - max balanced subarray
        }
    };