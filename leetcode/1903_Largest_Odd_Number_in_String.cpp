#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string largestOddNumber(string num) {

            int pos = -1;

            for(int i = num.size() - 1; i >= 0; i--)
            {
                if((num[i] - '0') % 2 == 1)
                {
                    pos = i;
                    break;
                }
            }

            if(pos == -1)
            {
                return "";
            }
            return num.substr(0, pos + 1);
            
        }
    };