#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        double sum = 0;
        double ans = 0;
        while(i < k)
        {
            sum = sum + nums[i];
            i++;
        }

        ans = sum;

        while(i < n)
        {
            sum = sum + nums[i] - nums[i - k];
            ans = max(ans, sum);
            i++;
        }
        
        return ans/k;
    }
};