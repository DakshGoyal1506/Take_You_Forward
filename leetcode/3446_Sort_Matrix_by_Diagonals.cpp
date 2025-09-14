#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        for(int start = n - 2; start >= 0; start--)
        {
            vector<int> temp;
            int j = 0, i = start;

            while(i < n && j < n)
            {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(temp.begin(), temp.end());

            for(int x : temp)
            {
                i--;
                j--;
                grid[i][j] = x;
            }
        }

        for(int start = n - 2; start > 0; start--)
        {
            vector<int> temp;
            int j = n - 1, i = start;

            while(i >= 0 && j >= 0)
            {
                temp.push_back(grid[i][j]);
                i--;
                j--;
            }

            sort(temp.begin(), temp.end());

            for(int x : temp)
            {
                i++; 
                j++;
                grid[i][j] = x;
            }
        }
        return grid;
    }
};