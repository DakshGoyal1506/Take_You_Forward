#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        for(int k = 0; k < n; k++)
        {
            if(nums[k] == 0)
            {
                swap(nums[k], nums[i]);
                i++;
            }
            else if(nums[k] == 2 && k < j)
            {
                swap(nums[k], nums[j]);
                j--;
                k--;
            }
        }
        
    }
};