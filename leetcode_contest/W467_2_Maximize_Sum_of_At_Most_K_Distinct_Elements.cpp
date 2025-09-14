#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxKDistinct(vector<int>& nums, int k) {

            set<int> st(nums.begin(), nums.end());
            vector<int> ans;

            for(int x : st)
            {
                ans.push_back(x);
            }

            sort(ans.begin(), ans.end(), greater<int>());
            
            if((int)ans.size() > k) ans.resize(k);
            return ans;
        }
};