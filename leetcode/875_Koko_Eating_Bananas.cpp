#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:

        int maxElement(vector<int>& piles)
        {
            int maxPiles = piles[0];
            
            for(int pile : piles)
            {
                maxPiles = max(pile, maxPiles);
            }

            return maxPiles;
        }

        long long hoursNeeded(vector<int>& piles, int rate)
        {
            long long hours = 0;

            for(int pile : piles)
            {
                // hours = hours + ceil((double)pile / (double)rate);
                // Equivalent to ceil((double)pile / rate) but done in integer arithmetic
                hours += (pile + (long long)rate - 1) / (long long)rate;
            }

            return hours;
        }

        int minEatingSpeed(vector<int>& piles, int h) {

            int low = 1, high = maxElement(piles);

            while(low <= high)
            {
                int mid = (low + high) / 2;
                long long hours = hoursNeeded(piles, mid);

                if(hours <= h)
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