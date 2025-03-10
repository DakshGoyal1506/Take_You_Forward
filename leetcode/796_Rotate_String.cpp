#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool rotateString(string s, string goal) {

            if (s.length() != goal.length())
            {
                return false;
            }

            string a = s + s;

            return a.find(goal) != string::npos;
            
        }
    };