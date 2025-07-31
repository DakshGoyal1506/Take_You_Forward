#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < n) {
            // direct match or '?'
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                i++; j++;
            }
            // record position of '*' and skip it
            else if (j < m && p[j] == '*') {
                star = j++;
                match = i;
            }
            // backtrack: try to extend the match of last '*'
            else if (star != -1) {
                j = star + 1;
                i = ++match;
            }
            else return false;
        }
        // skip any trailing '*' in pattern
        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};