#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMajority(vector<int>& arr) {
            // Code here

            int n = arr.size();
            int limit = int(n / 3);

            unordered_map<int, int> mp;

            for(int x : arr)
            {
                mp[x]++;
            }

            vector<int> ans;

            for(auto x : mp)
            {
                if(x.second > limit) ans.push_back(x.first);
            }

            sort(ans.begin(), ans.end());
            return ans;
        }
  };