#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int frogJump(vector<int>& heights) {

            int curr = 0;
            int prev = 0;
            int prev2 = 0;

            for(int i = 1; i < heights.size(); i++)
            {
                if(i == 1)
                {
                    curr = prev + abs(heights[1] - heights[0]);
                    prev2 = prev;
                    prev = curr;
                    continue;
                }
                curr = min(prev + abs(heights[i] - heights[i - 1]), prev2 + abs(heights[i] - heights[i - 2]));
                prev2 = prev;
                prev = curr;
            }
            return curr;
        }
    };