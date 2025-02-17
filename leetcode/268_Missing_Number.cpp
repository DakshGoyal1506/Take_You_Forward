#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for(int i = 0; i < n; i ++)
        {
            sum = sum + nums[i];
        }

        return total - sum;
        
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {

//         set<int> st;
//         int n = nums.size();
//         int max = -1;

//         for(int i = 0; i < n; i++)
//         {
//             st.insert(nums[i]);
//             if(max < nums[i])
//             {
//                 max = nums[i];
//             }
//         }

//         for(int i = 0; i <= max; i++)
//         {
//             if(st.find(i) == st.end())
//             {
//                 return i;
//             }
//         }
        
//     }
// };