#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        bool isValid(int i, int j, int m, int n)
        {
            if(i < 0 || i >= m) return false;
            if(j < 0 || j >= n) return false;
            return true;
        }

        void dfs(int row, int col, vector<vector<int>>& grid,
        vector<vector<int>>& visited, int n, int m)
        {
            visited[row][col] = 1;

            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(isValid(nrow, ncol, n, m) && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    dfs(nrow, ncol, grid, visited, n, m);
                }
            }
        }
    public:
        int numEnclaves(vector<vector<int>>& grid) {

            int n = grid.size();
            int m = grid[0].size();

            vector<vector<int>> visited(n, vector<int>(m, 0));

            
            for(int i = 0; i < n; i++)
            {
                if(!visited[i][0] && grid[i][0] == 1) dfs(i, 0, grid, visited, n, m);
                if(!visited[i][m-1] && grid[i][m-1] == 1) dfs(i, m-1, grid, visited, n, m);
            }

            for(int i = 0; i < m; i++)
            {
                if(!visited[0][i] && grid[0][i] == 1) dfs(0, i, grid, visited, n, m);
                if(!visited[n-1][i] && grid[n-1][i] == 1) dfs(n-1, i, grid, visited, n, m);
            }

            int ans = 0;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(!visited[i][j] && grid[i][j]) ans++;;
                }
            }
            return ans;
        }
    };