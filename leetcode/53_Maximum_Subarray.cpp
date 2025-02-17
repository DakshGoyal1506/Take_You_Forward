#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int max = -1;
        int maxelement = -9999999;

        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];

            if(nums[i] > maxelement)
            {
                maxelement = nums[i];
            }

            if(sum < 0)
            {
                sum = 0;
            } 

            if(max < sum)
            {
                max = sum;
            }
        }

        if(maxelement < 0)
        {
            return maxelement;
        }

        return max;
        
    }
};