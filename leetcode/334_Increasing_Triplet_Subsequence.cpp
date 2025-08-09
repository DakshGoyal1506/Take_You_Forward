#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) {
            if (x <= first) {
                first = x;              // new smallest
            }
            else if (x <= second) {
                second = x;             // new middle candidate
            }
            else {
                return true;            // x > second > first
            }
        }
        return false;
    }
};