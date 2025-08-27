#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> count;

        for(int x : nums)
        {
            count[x] ++;
            if(count[x] > n / 2) return x;
        }
        return -1;
        // int max = -1;
        // int ans = -1;

        // for(int i = 0; i < n; i++)
        // {
        //     if(count.find(nums[i]) != count.end())
        //     {
        //         count[nums[i]] = count[nums[i]] + 1;
        //         if(max < count[nums[i]])
        //         {
        //             max = count[nums[i]];
        //             ans = nums[i];
        //         }
        //     }
        //     else
        //     {
        //         count[nums[i]] = 1;
        //         if(max < count[nums[i]])
        //         {
        //             max = count[nums[i]];
        //             ans = nums[i];
        //         }
        //     }
        // }

        // return ans;
        
    }
};