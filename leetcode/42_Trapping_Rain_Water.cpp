#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {

            int n = height.size();
            vector<int> left(n, 0), right(n, 0);
            left[0] = height[0];
            right[n-1] = height[n-1];

            for(int i = 1; i < n; i++)
            {
                left[i] = max(height[i], left[i - 1]);
                // cout << left[i];
            }

            cout << endl;

            for(int i = n - 2; i >= 0; i--)
            {
                right[i] = max(height[i], right[i+1]);
                // cout << right[i];
            }
            cout << endl;

            for(int i = 0; i < n; i++)
            {
                right[i] = min(left[i], right[i]);
                // cout << right[i];
                right[i] = right[i] - height[i];
            }

            return accumulate(right.begin(), right.end(), 0);

            
        }
    };