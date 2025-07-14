#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int nextGreaterElement(int n) {

            string num = to_string(n);

            int l = num.length();

            int i = l - 2;
            int j = l - 1;

            while(i >= 0 && num[i] >= num[i + 1]) i--;

            if(i < 0) return -1;

            while(num[i] >= num[j]) j--;

            swap(num[i], num[j]);

            reverse(num.begin() + i + 1, num.end());

            long ans = stol(num);

            return ans > INT_MAX ? -1 : ans;
            
        }
    };