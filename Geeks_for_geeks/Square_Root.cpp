#include <iostream>
using namespace std;

class Solution{
    public:
    int floorSqrt(int n) {
        // Your code goes here
        int low = 1, high = n;

        while(low <= high)
        {
            long long mid = (low + high) / 2;
            long long val = mid * mid;

            if(val <= (long long)n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};