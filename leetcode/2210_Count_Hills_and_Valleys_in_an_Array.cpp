#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countHillValley(vector<int>& nums) {

            int n = nums.size();
            vector<int> arr;
            arr.push_back(nums[0]);

            for(int i = 1; i < n; i++)
            {
                if(nums[i] == nums[i - 1]) continue;
                else arr.push_back(nums[i]);
            }

            n = arr.size();
            int i = 1;
            int ans = 0;

            while(i < n - 1)
            {
                if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ans++;
                else if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) ans++;

                i++;
            }
            return ans;
        }
    };