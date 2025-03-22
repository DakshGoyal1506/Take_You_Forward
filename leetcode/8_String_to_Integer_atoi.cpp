#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string ans;
        int i = 0;
        bool isNegative = false;

        // Skip leading whitespace
        for(; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            else break;
        }

        // Handle sign
        if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-');
            i++;
        }

        // Process digits
        long long result = 0; // Using long long to handle overflow
        for(; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                result = result * 10 + (s[i] - '0');
                
                // Check for overflow
                if(isNegative && result > 2147483648) {
                    return INT_MIN;
                }
                if(!isNegative && result > 2147483647) {
                    return INT_MAX;
                }
            } else {
                break;
            }
        }

        // Apply sign and return
        return isNegative ? -result : result;
    }
};