#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {

            int n = nums.size();
            int jump = 0, currentEnd = 0, MaxIndex = 0;

            for(int i = 0; i < n; i++)
            {
                MaxIndex = max(MaxIndex, i + nums[i]);

                if(i == currentEnd)
                {
                    jump++;
                    currentEnd = MaxIndex;
                }
            }

            return jump;
        }
    };