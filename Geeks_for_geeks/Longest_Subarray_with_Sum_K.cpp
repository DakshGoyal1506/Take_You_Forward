#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution{
    public:
    int longestSubarray(vector<int> arr, int k)
    {
        unordered_map<int, int> map;
        int maxlength = 0;
        int sum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            sum = sum + arr[i];

            if(sum == k)
            {
                maxlength = i + 1;
            }
            if(map.find(sum - k) != map.end())
            {
                maxlength = max(maxlength, i - map[sum - k]);
            }

            if(map.find(sum) == map.end())
            {
                map[sum] = i;
            }
        }

        return maxlength;
    }
};
