#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSum(vector<int>& nums) {

            int maxnum = *max_element(nums.begin(), nums.end());

            if(maxnum <= 0) return maxnum;
            int sum = 0;

            unordered_set<int> st;

            int n = nums.size();

            for(int i = 0; i < n; i++)
            {
                if(nums[i] < 0 || st.count(nums[i]) != 0) continue;

                sum = sum + nums[i];
                st.insert(nums[i]);
            }
            return sum;
        }
    };

// class Solution {
//     public:
//         int maxSum(vector<int>& nums) {

//             unordered_set<int> st;

//             int left = 0, right = 0;
//             int n = nums.size();
//             int sum = 0, best = INT_MIN;

//             while(right < n)
//             {
//                 while(st.count(nums[right]))
//                 {
//                     sum = sum - nums[left];
//                     st.erase(nums[left]);
//                     left++;
//                 }

//                 sum = sum + nums[right];
//                 st.insert(nums[right]);
//                 right++;
//                 best = max(sum, best);

//                 if (sum < 0) 
//                 {
//                     sum = 0;
//                     st.clear();
//                     left = right;
//                 }
//             }
//             return best;
//         }
//     };