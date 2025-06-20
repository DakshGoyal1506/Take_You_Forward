#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int kDistinctChar(string& s, int k) {
            //your code goes here
            int n = s.length();
            int left = 0, right = 0;
            unordered_map<char, int> mp;
            int ans = 0;

            while(right < n)
            {
                mp[s[right]]++;

                while(mp.size() > k)
                {
                    mp[s[left]]--;
                    if(mp[s[left]] == 0)
                    {
                        mp.erase(s[left]);
                    }
                    left++;
                }

                if(mp.size() <= k)
                {
                    ans = max(ans, right - left + 1);
                }

                right++;
            }

            return ans;
        }
    };