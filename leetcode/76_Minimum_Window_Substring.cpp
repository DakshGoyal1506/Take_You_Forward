#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {

            int left = 0, right = 0;
            int hash[256] = {0};
            int index = -1;
            int MinLength = INT_MAX;
            int n = s.length();

            for(char c : t)
            {
                hash[c]++;
            }

            int count = 0;

            while(right < n)
            {
                if(hash[s[right]] > 0)
                {
                    count++;
                }
                hash[s[right]]--;

                while(count == t.size())
                {
                    if(right - left + 1 < MinLength)
                    {
                        MinLength = right - left + 1;
                        index = left;
                    }

                    hash[s[left]]++;

                    if(hash[s[left]] > 0)
                    {
                        count--;
                    }

                    left++;
                }

                right++;
            }

            return (index == -1) ? "" : s.substr(index, MinLength);
            
        }
    };