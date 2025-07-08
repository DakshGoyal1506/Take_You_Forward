#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        bool isValid(int i, int j, int n, int m)
        {
            if(i < 0 || i >= n) return false;
            if(j < 0 || j >= m) return false;
            return true;
        }

        bool bfs(vector<vector<int>>& grid, int t)
        {
            if(grid[0][0] > t) return false;

            int n = grid.size();

            vector<vector<bool>> visited(n, vector<bool>(n, 0));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;

            while(!q.empty())
            {
                auto x = q.front();
                q.pop();

                int row = x.first;
                int col = x.second;

                for(int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(!isValid(nRow, nCol, n, n) || visited[nRow][nCol] || grid[nRow][nCol] >t) continue;

                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
            return visited[n-1][n-1];
        }
    public:
        int swimInWater(vector<vector<int>>& grid) {

            int n = grid.size();
            int low = 0;
            int high = n*n - 1;

            while(low < high)
            {
                int mid = (low + high) / 2;

                if(bfs(grid, mid))
                {
                    high = mid;
                }
                else low = mid + 1;
            }
            return high;
        }
    };