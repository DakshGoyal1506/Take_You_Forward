#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:

        bool Possible(vector<int>& bloomDay, int day, int m, int k)
        {
            int count = 0, numBoq = 0;
            int n = bloomDay.size();

            for(int i = 0; i < n; i++)
            {
                if(bloomDay[i] <= day)
                {
                    count ++;
                }
                else
                {
                    numBoq = numBoq + (count/k);
                    count = 0;
                }
            }

            numBoq = numBoq + (count/k);

            return (numBoq >= m);
        }

        int minDays(vector<int>& bloomDay, int m, int k) {

            long long val = m * 1ll * k * 1ll;
            int n = bloomDay.size();

            if(val > n)
            {
                return -1;
            }

            int minval = INT_MAX, maxval = INT_MIN;

            for(int i = 0; i < n; i++)
            {
                minval = min(minval, bloomDay[i]);
                maxval = max(maxval, bloomDay[i]);
            }

            int low = minval, high = maxval;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(Possible(bloomDay, mid, m, k))
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
