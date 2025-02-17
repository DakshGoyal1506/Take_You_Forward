#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        int max = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else if(nums[i] == 0)
            {
                if(max < count)
                {
                    max = count;
                }
                count = 0;
            }
        }

        if(max < count)
        {
            max = count;
        }

        return max;
        
    }
};