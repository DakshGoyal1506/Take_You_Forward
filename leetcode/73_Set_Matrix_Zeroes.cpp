#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for(int i = 0; i < rows; i ++)
        {
            if(matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        for(int i = 0; i < cols; i ++)
        {
            if(matrix[0][i] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColZero)
        {
            for(int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

        if(firstRowZero)
        {
            for(int i = 0; i < cols; i++)
            {
                matrix[0][i] = 0;
            }
        }

        return;
        
    }
};