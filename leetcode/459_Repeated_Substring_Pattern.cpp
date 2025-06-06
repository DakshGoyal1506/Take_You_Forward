#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool repeatedSubstringPattern(string s) {

            string s1 = s + s;

            int position = s1.find(s, 1);

            return position < s.size();
            
        }
    };