#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         vector<int> findAnagrams(string s, string p) {

//             vector<int> ans;
//             int n = p.length();
//             int index = s.length() - p.length();

//             for(int i = 0; i <= index; i++)
//             {
//                 if(isAnagram(s.substr(i, n), p))
//                 {
//                     ans.push_back(i);
//                 }
//             }

//             return ans;
            
//         }

    
//     private:
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
        vector<int> findAnagrams(string s, string p) {

            vector<int> ans;
            int n = s.size(), m = p.size();

            if(n < m)
            {
                return ans;
            }

            vector<int> freqS(26, 0), freqP(26, 0);

            for(int i = 0; i < m; i++)
            {
                freqS[s[i] - 'a']++;
                freqP[p[i] - 'a']++;
            }

            if(freqS == freqP)
            {
                ans.push_back(0);
            }

            for(int i = m; i < n; i++)
            {
                freqS[s[i] - 'a'] ++;
                freqS[s[i - m] - 'a'] --;
                
                if(freqS == freqP)
                {
                    ans.push_back(i - m + 1);
                }
            }

            return ans;
            
        }
    };