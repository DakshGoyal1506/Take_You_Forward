#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    public:

        int numDays(vector<int>& weights, int capacity)
        {
            int days = 0;
            int load = 0;

            for(int weight : weights)
            {
                if(load + weight > capacity)
                {
                    days = days + 1;
                    load = weight;
                }
                else
                {
                    load = load + weight;
                }
            }

            return days;
        }

        int shipWithinDays(vector<int>& weights, int days) {

            int low = *max_element(weights.begin(), weights.end());
            int high = accumulate(weights.begin(), weights.end(), 0);

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(numDays(weights, mid) < days)
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