#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int heightChecker(vector<int>& heights) {

            vector<int> expected = heights;

            int n = heights.size();
            int ans = 0;

            for(int i = n-1; i >= 0; i--)
            {
                int index = i;
                for(int j = 0; j <= i; j++)
                {
                    if(expected[index] < expected[j]) index = j;
                }
                swap(expected[i], expected[index]);

                if(expected[i] != heights[i]) ans++;
            }
            return ans;
        }
    };