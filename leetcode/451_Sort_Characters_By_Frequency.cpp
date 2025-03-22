#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> dic;
            for(char a: s) {
                dic[a]++;
            }

            vector<pair<char,int>> arr(dic.begin(), dic.end());

            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
                return a.second > b.second;
            });

            string ans;
            for(auto &p : arr) {
                ans.append(p.second, p.first);
            }
            
            return ans;
        }
    };