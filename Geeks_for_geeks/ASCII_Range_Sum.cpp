#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> asciirange(string& s) {
            // code here

            unordered_map<char, pair<int, int>> mp;
            int n = s.length();
            for(int i = 0;i < n; i++)
            {
                if(mp.find(s[i]) == mp.end())
                {
                    mp[s[i]].first = i;
                    mp[s[i]].second = -1;
                }
                mp[s[i]].second = i;
            }

            vector<int> ans;

            for(auto& x : mp)
            {
                int first = x.second.first, last = x.second.second;

                if(first < last)
                {
                    int sum = 0;
                    for(int i = first + 1; i < last; i++)
                    {
                        sum = sum + static_cast<int>(s[i]);
                    }
                    if(sum) ans.push_back(sum);
                }
            }
            return ans;
        }
  };