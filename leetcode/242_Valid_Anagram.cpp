#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         bool isAnagram(string s, string t) {

//             if(s.length() != t.length())
//             {
//                 return false;
//             }

//             sort(s.begin(), s.end());
//             sort(t.begin(), t.end());

//             int n = s.length();

//             for(int i = 0; i < n; i++)
//             {
//                 if(s[i] != t[i])
//                 {
//                     return false;
//                 }
//             }

//             return true;
            
//         }
//     };

class Solution {
    public:
        bool isAnagram(string s, string t) {

            unordered_map<char, int> freq;

            for(char ch1 : s)
            {
                freq[ch1] = freq[ch1] + 1;
            }

            for(char ch2 : t)
            {
                freq[ch2] = freq[ch2] - 1;
            }

            for(auto &pair : freq)
            {
                if(pair.second != 0)
                {
                    return false;
                }
            }

            return true;
            
        }
    };