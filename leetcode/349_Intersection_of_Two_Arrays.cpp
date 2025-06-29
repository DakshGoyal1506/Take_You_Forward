#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

            unordered_set<int> st;
            vector<int> ans;

            for(int x : nums1)
            {
                st.insert(x);
            }

            for(int x : nums2)
            {
                if(st.find(x) != st.end()) 
                {
                    ans.push_back(x);
                    st.erase(x);
                }
            }
            return ans;
        }
    };