#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {

            unordered_map<char, int> freq;

            for(char ch : magazine)
            {
                freq[ch] = freq[ch] + 1;
            }

            for(char ch : ransomNote)
            {
                freq[ch] = freq[ch] - 1;
            }

            for(auto &pair : freq)
            {
                if(pair.second < 0) return false;
            }
            return true;
        }
    };