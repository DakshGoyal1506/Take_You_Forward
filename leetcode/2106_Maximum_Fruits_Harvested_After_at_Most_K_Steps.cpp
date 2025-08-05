#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

            int n = fruits.size();
            int ans = 0, sum = 0;
            int i = 0;

            for(int j = 0; j < n; j++)
            {
                sum = sum + fruits[j][1];

                while(i <= j)
                {
                    int left = fruits[i][0];
                    int right = fruits[j][0];
                    int d1 = abs(left - startPos);
                    int d2 = abs(right - startPos);
                    int cost = 0;

                    if(left <= startPos && startPos <= right) cost = min(2*d1 + d2, d1 + 2*d2);
                    else cost = max(d1, d2);

                    if(cost <= k) break;
                    sum = sum - fruits[i][1];
                    i++;
                }

                ans = max(ans, sum);
            }
            return ans;
        }
    };