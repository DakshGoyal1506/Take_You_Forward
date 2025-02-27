#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    public:

        long long sumValue(vector<int>& nums, int mid)
        {
            long long sum = 0;

            for(int num : nums)
            {
                // sum = sum + ceil((double)num / (double) mid);
                sum = sum + (num + mid - 1) / mid;
            }

            return sum;
        }

        int smallestDivisor(vector<int>& nums, int threshold) {

            int low = 1, high = *max_element(nums.begin(), nums.end());

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(sumValue(nums, mid) <= (long long)threshold)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            return low;
            
        }
    };