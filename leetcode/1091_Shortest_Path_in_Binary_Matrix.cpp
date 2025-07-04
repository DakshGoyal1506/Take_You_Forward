#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> delRow = {1, 1, 1, 0, -1, -1, -1, 0};
        vector<int> delCol = {-1, 0, 1, 1, 1, 0, -1, -1};

        bool isValid(int i, int j, int n, int m)
        {
            if(i < 0 || i >= n) return false;
            if(j < 0 || j >= m) return false;
            return true;
        }
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

            int n = grid.size();
            int m = grid[0].size();

            if(grid[0][0] || grid[n-1][m-1]) return -1;

            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 1;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[0][0] = true;

            queue<pair<int, pair<int,int>>> q;
            q.push({1, {0,0}});

            while(!q.empty())
            {
                auto it = q.front();
                q.pop();

                int dis = it.first;
                int row = it.second.first;
                int col = it.second.second;

                if(row == n - 1 && col == m - 1) return dis;

                for(int i = 0; i < 8; i++)
                {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(isValid(nrow, ncol, n, m) &&
                        grid[nrow][ncol] == 0 &&
                        dis + 1 < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = dis + 1;
                        visited[nrow][ncol] = true;

                        if(nrow == n - 1 && ncol == m - 1) return dis + 1;

                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
            return -1;
        }
    };