#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int left = 0, right = n - 1;

        int ans = 0;

        while(left < right)
        {
            int temp = (right - left) * min(height[left], height[right]);
            ans = max(ans, temp);

            if(height[left] > height[right]) right--;
            else left++;
        }
        return ans;
    }
};