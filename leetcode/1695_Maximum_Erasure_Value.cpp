#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {

            int l = 0, r = 0;
            int n = nums.size();

            int sum = 0;
            unordered_set<int> st;
            int ans = -1;

            while(r < n)
            {
                if(st.find(nums[r]) != st.end())
                {
                    while(st.find(nums[r]) != st.end())
                    {
                        sum = sum - nums[l];
                        st.erase(nums[l]);
                        l++;
                    }
                }
                sum = sum + nums[r];
                st.insert(nums[r]);
                ans = max(sum, ans);
                r++;
            }
            return ans;
            
        }
    };