#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {

            int n = matrix.size();

            for(int i = n - 2; i >= 0; i--)
            {
                for(int j = 0; j < n; j++)
                {
                    int left = j == 0? INT_MAX : matrix[i+1][j-1];
                    int mid = matrix[i+1][j];
                    int right = j == n - 1 ? INT_MAX : matrix[i+1][j+1];

                    matrix[i][j] = matrix[i][j] + min({left, mid, right});
                }
            }
            int ans = INT_MAX;
            for(int x : matrix[0])
            {
                ans = min(ans, x);
            }
            return ans;
        }
    };