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

        void dfs(int row, int col,
        vector<vector<char>>& board,
        vector<vector<int>>& visited,
        int n, int m)
        {
            visited[row][col] = 1;
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if( isValid(nrow, ncol, n, m) && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
                {
                    dfs(nrow, ncol, board, visited, n, m);
                }
            }
        }
    public:
        void solve(vector<vector<char>>& board) {

            int n = board.size();
            int m = board[0].size();

            vector<vector<int>> visited(n, vector<int>(m, 0));

            for(int i = 0; i < n; i++)
            {
                if(!visited[i][0] && board[i][0] == 'O') dfs(i, 0, board, visited, n, m);
                if(!visited[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, board, visited, n, m);
            }

            for(int i = 0; i < m; i++)
            {
                if(!visited[0][i] && board[0][i] == 'O') dfs(0, i, board, visited, n, m);
                if(!visited[n-1][i] && board[n-1][i] == 'O') dfs(n-1, i, board, visited, n, m);
            }

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
                }
            }

            return;
            
        }
    };