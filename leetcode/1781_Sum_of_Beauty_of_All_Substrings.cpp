#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int ans = 0;
        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++)
        {
            fill(freq.begin(), freq.end(), 0);
            for(int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int minFreq = 100000, maxFreq = -1;

                for(int x : freq)
                {
                    if(x == 0) continue;
                    minFreq = min(x, minFreq);
                    maxFreq = max(x, maxFreq);
                }

                ans = ans + maxFreq - minFreq;
            }
        }
        return ans;
    }
};