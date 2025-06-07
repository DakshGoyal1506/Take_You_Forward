#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            if(s.length() == 0 || s.length() == 1)
            {
                return s.length();
            }

            int length = 1;
            int left = 0, right = 0;

            vector<bool> v(26, false);

            while(right < s.length())
            {
                while( v[s[right] - 'a'] == true)
                {
                    v[s[left] - 'a'] = false;
                    left++;
                }

                v[s[right] - 'a'] = true;

                length = max(length, (right - left + 1));
                right++;
            }

            return length;
            
        }
    };