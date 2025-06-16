#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//             int n = nums.size();
//             vector<int> ans;

//             for(int i = 0; i <= n - k; i++)
//             {
//                 int maxNum = nums[i];
//                 for(int j = i; j < i + k; j++)
//                 {
//                     maxNum = max(maxNum, nums[j]);
//                 }

//                 ans.push_back(maxNum);
//             }

//             return ans;
            
//         }
//     };

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {

            deque <int> dq;
            vector<int> ans;
            int n = nums.size();

            for(int i = 0; i < n; i++)
            {
                while(!dq.empty() && dq.front() == i - k) dq.pop_front();

                while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

                dq.push_back(i);

                if(i >= k - 1) ans.push_back(nums[dq.front()]);
            }
            return ans;
        }
    };