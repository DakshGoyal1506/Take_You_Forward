#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

        int firstIndex(vector<int>& nums, int target)
        {
            int n = nums.size();
            int low = 0, high = n - 1;
            int mid;

            int ans = -1;

            while(low <= high)
            {
                mid = (low + high) / 2;
                if(nums[mid] == target)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else if(nums[mid] < target)
                {
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            return ans;
        }

        int countFreq(vector<int>& arr, int target) {
            
            int first = firstIndex(arr, target);
            int ans = 0;

            while(arr[first] == target)
            {
                ans ++;
                first ++;
            }

            return ans;
        }
    };