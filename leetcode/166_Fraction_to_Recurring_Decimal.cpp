#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string fractionToDecimal(int numerator0, int denominator0) {

            if (numerator0 == 0)
            {
                return "0";
            }

            long long numerator = numerator0;
            long long denominator =denominator0;

            string ans = (numerator < 0) ^ (denominator < 0) ? "-" : "";

            numerator = abs(numerator);
            denominator = abs(denominator);

            ans = ans + to_string(numerator / denominator);

            long long rem = numerator % denominator;

            if(rem == 0)
            {
                return ans;
            }

            ans.append(".");
            unordered_map<long long, int> mp;

            while(rem > 0)
            {
                if(mp.find(rem) != mp.end())
                {
                    ans.insert(mp[rem], "(");
                    ans.append(")");
                    break;
                }

                mp[rem] = ans.size();

                rem = rem * 10;

                ans = ans + to_string(rem / denominator);
                rem = rem % denominator;
            }

            return ans;
            
        }
    };