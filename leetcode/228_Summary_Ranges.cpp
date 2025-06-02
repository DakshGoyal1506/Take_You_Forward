#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {

            vector <string> ans;

            int i = 0, j = 0;
            int n = nums.size();

            auto range = [&](int start, int end)
            {
                return start == end ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[end]);
            };

            while(i < n)
            {
                j = i;
                while(j + 1 < n && nums[j + 1] == nums[j] + 1)
                {
                    j++;
                }

                ans.push_back(range(i, j));

                i = j + 1;
            }

            return ans;
            
        }
    };