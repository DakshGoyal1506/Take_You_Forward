#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {

            string s1 = "";

            for(char ch : s)
            {
                if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                {
                    s1.push_back(ch);
                }
                else if(ch >= 'A' && ch <= 'Z')
                {
                    s1.push_back(tolower(ch));
                }
                else
                {
                    continue;
                }
            }

            int i = 0, j = s1.length() - 1;

            while(i < j)
            {
                if(s1[i] == s1[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }

            return true;
            
        }
    };