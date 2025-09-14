#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {

        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        for(char c : s)
        {
            if(st.find(c) != st.end()) return true;
        }
        return false;
    }
};