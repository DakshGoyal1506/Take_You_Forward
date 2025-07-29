#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int balanceSums(vector<vector<int>>& mat) {
            // code here

            int n = mat.size();
            int sum = 0;
            int maxrow = 0;

            for(int i = 0; i < n; i++)
            {
                int curr = 0;
                for(int x: mat[i])
                {
                    curr = curr + x;
                }
                sum = sum + curr;
                maxrow = max(maxrow, curr);
            }

            int maxRowSum = n * maxrow;

            int maxCol = 0;
            for(int i = 0; i < n; i++)
            {
                int curr = 0;
                for(int j = 0; j < n; j++)
                {
                    curr = curr + mat[j][i];
                }
                maxCol = max(maxCol, curr);
            }

            int maxColSum = n * maxCol;

            return  max(maxRowSum - sum, maxColSum - sum);
        }
  };