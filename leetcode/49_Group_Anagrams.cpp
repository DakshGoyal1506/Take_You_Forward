#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {

            unordered_map<string, vector<string>> mp;

            for(string str: strs)
            {
                string key = str;
                sort(key.begin(), key.end());

                mp[key].emplace_back(str);
            }

            vector<vector<string>> ans;

            for(auto& pair: mp)
            {
                ans.emplace_back(pair.second);
            }
            return ans;
        }
    };