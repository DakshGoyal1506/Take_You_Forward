#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {

        int n = nums.size();
        int low = 0, high = n - 1;
        int min_element = INT_MAX, index = -1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[low] < nums[high])
            {
                if(nums[low] < min_element)
                {
                    min_element = nums[low];
                    index = low;
                }
            }
            if(nums[low] <= nums[mid])
            {
                if(nums[low] < min_element)
                {
                    min_element = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else
            {
                if(nums[mid] < min_element)
                {
                    min_element = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};