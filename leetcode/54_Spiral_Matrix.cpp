#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {

            vector<int> result;

            if(matrix.empty())
            {
                return result;
            }

            int n = matrix.size();
            int m = matrix[0].size();
            int top = 0, bottom = n - 1;
            int left = 0, right = m - 1;

            while(top <= bottom && left <= right)
            {
                if(top <= bottom)
                {
                    for(int j = left; j <= right; j++)
                    {
                        result.push_back(matrix[top][j]);
                    }
                    top++;
                }

                if(left <= right)
                {
                    for(int i = top; i <= bottom; i++)
                    {
                        result.push_back(matrix[i][right]);
                    }
                    right--;
                }

                if(top <= bottom)
                {
                    for(int j = right; j >= left; j--)
                    {
                        result.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                }

                if(left <= right)
                {
                    for(int i = bottom; i >= top; i--)
                    {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }

            return result;

            
        }
    };