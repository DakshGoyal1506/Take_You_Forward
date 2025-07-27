#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {

            int n = triangle.size();
            if(n == 1) return triangle[0][0];

            for(int i = 1; i < n; i++) triangle[i][0] = triangle[i][0] + triangle[i - 1][0];
            int m = 0;

            for(int i = 1; i < n; i++)
            {
                m = triangle[i].size();
                for(int j = 1; j < m - 1; j++)
                {
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
                triangle[i][m - 1] = triangle[i][m - 1] + triangle[i - 1][m - 2];
            }

            int ans = INT_MAX;
            for(int x : triangle[n - 1]) ans = min(ans, x);
            return ans;
        }
    };