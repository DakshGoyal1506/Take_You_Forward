#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> digits;

        for(int i = 0; i < n; i++)
        {
            digits[nums[i]] = i;
        }

        for(int i = 0; i < n ; i++)
        {
            int j = target - nums[i];
            
            if(digits.find(j) != digits.end() && (digits[j] != i))
            {
                ans.push_back(i);
                ans.push_back(digits[j]);
                return ans;
            }
        }

        return ans;
    }
};