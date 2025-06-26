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
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

            int n = mat.size();
            int m = mat[0].size();

            vector<vector<int>> vis(n, vector<int>(m, 0));
            vector<vector<int>> dis(n, vector<int>(m, 0));

            queue<pair<pair<int,int>, int>> q;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(mat[i][j] == 0)
                    {
                        vis[i][j] = 1;
                        q.push({{i, j}, 0});
                    }
                }
            }

            while(!q.empty())
            {
                auto x = q.front();
                q.pop();

                int row = x.first.first;
                int col = x.first.second;
                dis[row][col] = x.second;

                for(int i = 0; i < 4; i++)
                {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if(isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 0)
                    {
                        vis[newRow][newCol] = 1;
                        q.push({{newRow, newCol}, x.second + 1});
                    }
                }
            }

            return dis;
            
        }
    };