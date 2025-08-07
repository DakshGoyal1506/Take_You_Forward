#include<bits/stdc++.h>
#include<numeric>
using namespace std;

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {

            if(str1 + str2 != str2 + str1) return "";

            int k = std::gcd((int)str1.size(), (int)str2.size());
            return str1.substr(0, k);
        }
    };