#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];

        for(int i = 1; i < n; i++)
        {
            if(nums[i - 1] <= nums[i])
            {
                sum = sum + nums[i];
            }
            else
            {
                maxSum = max(maxSum, sum);
                sum = nums[i];
            }
        }

        maxSum = max(maxSum, sum);

        return maxSum;
        
    }
};