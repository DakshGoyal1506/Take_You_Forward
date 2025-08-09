#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size(), m = t.size();
        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(j < m && s[i] != t[j]) j++;
            else
            {
                i++;
                j++;
            }

        }
        
        if(i == n) return true;
        return false;
    }
};