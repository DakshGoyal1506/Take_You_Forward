#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;
        int count = 0;

        for(int x : nums)
        {
            if(x == 0)
            {
                count++;
                ans = ans + count;
            }
            else count = 0;
        }
        return ans;
    }
};