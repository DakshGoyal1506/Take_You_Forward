#include <bits/stdc++.h>
using namespace std;

class Solution
{

    private:
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};

        bool isValid(int i, int j, int n, int m)
        {
            if(i < 0 || i >= n) return false;
            if(j < 0 || j >= m) return false;
            return true;
        }

        void dfs(int row, int col,
                vector<vector<int>>& grid,
                vector<vector<bool>>& visited,
                vector<pair<int,int>>& path,
                int baseRow, int baseCol)
        {
            int n = grid.size();
            int m = grid[0].size();

            path.push_back({row-baseRow, col-baseCol});
            visited[row][col] = 1;

            for(int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow, nCol, n, m)&&
                    grid[nRow][nCol]&&
                    !visited[nRow][nCol])
                {
                    dfs(nRow, nCol, grid, visited, path, baseRow, baseCol);
                }
            }
        }
    public:
        int countDistinctIslands(vector<vector<int>> &grid){
            
            int n = grid.size();
            int m = grid[0].size();

            vector<vector<bool>> visited(n, vector<bool>(m, false));

            set <vector<pair<int,int>>> st;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] == 1 && !visited[i][j])
                    {
                        vector<pair<int,int>> path;
                        dfs(i, j, grid, visited, path, i, j);
                        st.insert(path);
                    }
                }
            }
            return st.size();
        }
};
