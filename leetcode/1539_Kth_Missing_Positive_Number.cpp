#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {

            int low = 0, high = arr.size() - 1;

            while(low <= high)
            {
                int mid = (low + high) / 2;
                int missingsnumbers = arr[mid] - (mid + 1);

                if(missingsnumbers < k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return k + high + 1;
            
        }
    };