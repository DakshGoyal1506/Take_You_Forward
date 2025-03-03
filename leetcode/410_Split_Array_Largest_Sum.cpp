#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    public:

        int parts(vector<int>&nums, int mid)
        {
            int divisions = 1;
            int sum = 0;

            for(int num : nums)
            {
                if(num + sum <= mid)
                {
                    sum = sum + num;
                }
                else
                {
                    sum = num;
                    divisions++;
                }
            }

            return divisions;
        }

        int splitArray(vector<int>& nums, int k) {

            int low = *max_element(nums.begin(), nums.end());
            int high = accumulate(nums.begin(), nums.end(), 0);

            while (low <= high)
            {
                int mid = (low + high) / 2;
                int divisions = parts(nums, mid);

                if(divisions > k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
            return low;
        }
    };