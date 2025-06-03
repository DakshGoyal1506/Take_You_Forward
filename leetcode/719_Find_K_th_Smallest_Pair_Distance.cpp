#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int smallestDistancePair(vector<int>& nums, int k) {

            sort(nums.begin(), nums.end());

            int low = 0;
            int high = nums.back() - nums.front();

            while(low <= high)
            {
                int mid = (low + high) / 2;

                int n = pairDistance(nums, mid);

                if(n < k)
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

    private:

        int pairDistance(vector<int>& nums, int distance)
        {
            int count = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                int value = nums[i] - distance;
                int index = lower_bound(nums.begin(), nums.end(), value) - nums.begin();

                count = count + i - index;
            }

            return count;
        }
    };