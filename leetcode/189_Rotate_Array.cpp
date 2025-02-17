#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    void reversearray(vector<int>& nums, int l, int r)
    {
        while(l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reversearray(nums, 0, n - 1);
        reversearray(nums, 0, k - 1);
        reversearray(nums, k, n - 1);

    }
};