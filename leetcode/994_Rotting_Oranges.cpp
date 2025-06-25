#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        bool isValid(int i,int j,int n,int m)
        {
            if(i < 0 || i >= n) return false;
            if(j < 0 || j >= m) return false;

            return true;
        }
    public:
        int orangesRotting(vector<vector<int>>& grid) {

            queue<pair<int, int>> q;
            int total = 0;
            int count = 0;
            int time = 0;

            int n = grid.size();
            int m = grid[0].size();

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] != 0) total++;
                    if(grid[i][j] == 2)
                    {
                        count++;
                        q.push({i, j});
                    }
                }
            }

            while(!q.empty())
            {
                int k = q.size();
                // count = count + k;

                while(k--)
                {
                    auto x = q.front();
                    q.pop();

                    int row0 = x.first;
                    int col0 = x.second;

                    for(int i = 0; i < 4; i++)
                    {
                        int row = row0 + delRow[i];
                        int col = col0 + delCol[i];

                        if(isValid(row, col, n, m) && grid[row][col] == 1)
                        {
                            grid[row][col] = 2;
                            count ++;
                            q.push({row, col});
                        }
                    }
                }

                if(!q.empty()) time ++;
            }

            if(total == count) return time;

            return -1;
        }
    };