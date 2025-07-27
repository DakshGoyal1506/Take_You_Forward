#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
    public:
        long long numOfSubsequences(string s) {

            int n = s.length();
            vector<ll> prefix_L(n+1, 0), prefix_LC(n+1, 0);
            ll countL = 0, countLC = 0, base = 0;

            for(int i = 0; i < n; i++)
            {
                prefix_L[i] = countL;
                prefix_LC[i] = countLC;
                if(s[i] == 'L') countL++;
                else if(s[i] == 'C') countLC = countLC + countL;
                else if(s[i] == 'T') base = base + countLC;
            }
            prefix_L[n] = countL;
            prefix_LC[n] = countLC;

            vector<ll> suffix_T(n+1, 0), suffix_CT(n+1, 0);
            ll countT = 0, countCT = 0;

            for(int i = n - 1; i >= 0; i--)
            {
                if(s[i] == 'T') countT++;
                else if(s[i] == 'C') countCT = countCT + countT;
                suffix_T[i] = countT;
                suffix_CT[i] = countCT;
            }
            suffix_T[n] = 0;
            suffix_CT[n] = 0;

            ll insertL = 0, insertC = 0, insertT = 0;

            for(int i = 0; i <= n; i++)
            {
                insertL = max(insertL, suffix_CT[i]);
                insertC = max(insertC, prefix_L[i] * suffix_T[i]);
                insertT = max(insertT, prefix_LC[i]);
            }

            ll ans = base + max({insertL, insertC, insertT});
            return ans;
        }
    };