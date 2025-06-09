#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {

            vector<int> charfreq(26, 0);
            int left = 0, right = 0;
            int maxCount = 1;

            for(right = 0; right < s.length(); right++)
            {
                charfreq[s[right] - 'A']++;

                maxCount = max(maxCount, charfreq[s[right] - 'A']);

                if((right - left + 1 - maxCount) > k)
                {
                    charfreq[s[left] - 'A']--;
                    left++;
                }
            }

            return right - left;
            
        }
    };