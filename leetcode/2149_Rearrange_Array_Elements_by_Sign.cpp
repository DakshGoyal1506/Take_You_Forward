#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0, j = 0; i < n/2; i++, j = j + 2)
        {
            nums[j] = pos[i];
            nums[j+1] = neg[i];
        }

        return nums;
        
    }
};