#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            
            int n = s.length();
            if(n == 0) return "";

            int start = 0, maxLength = 1;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j <=1; j++)
                {
                    int low = i;
                    int high = j + i;

                    while(low >= 0 && high < n && s[low] == s[high])
                    {
                        int currLen = high - low + 1;

                        if(currLen > maxLength)
                        {
                            start = low;
                            maxLength = currLen;
                        }

                        low --;
                        high ++;
                    }
                }
            }

            return s.substr(start, maxLength);
        }
    };