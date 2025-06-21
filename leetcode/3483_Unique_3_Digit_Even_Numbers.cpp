#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            // hundreds place cannot be 0
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    // units place must be even
                    if (digits[k] % 2 != 0) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }
            }
        }
        return seen.size();
    }
};