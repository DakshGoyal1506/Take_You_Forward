#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mapping{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int num = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(i + 1 < s.size() && mapping[s[i]] < mapping[s[i+1]])
            {
                num = num - mapping[s[i]];
            }
            else{
                num = num + mapping[s[i]];
            }
        }
        return num;
    }
};