#include <bits/stdc++.h>
using namespace std;

class disSet{
    public:
        vector<int> parent, rank, size;

        disSet(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findParent(int node)
        {
            return (parent[node] == node) ? node : parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v)
        {
            int uPar_u = findParent(u);
            int uPar_v = findParent(v);

            if(uPar_u == uPar_v) return ;

            if(size[uPar_u] < size[uPar_v])
            {
                parent[uPar_u] = uPar_v;
                size[uPar_v] += size[uPar_u];
            }
            else
            {
                parent[uPar_v] = uPar_u;
                size[uPar_u] += size[uPar_v];
            }
        }
};

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
    public:
        int largestIsland(vector<vector<int>>& grid) {

            int n = grid.size();
            int m = grid[0].size();

            disSet ds(n*m);

            for(int row = 0; row < n; row++)
            {
                for(int col = 0; col < m; col++)
                {
    
                    if(grid[row][col] == 0) continue;
    
                    int node = row * n + col;
    
                    for(int i = 0; i < 4; i++)
                    {
                        int nRow = delRow[i] + row;
                        int nCol = delCol[i] + col;
    
                        if(isValid(nRow, nCol, n, m) && grid[nRow][nCol])
                        {
                            int newNode = nRow * n + nCol;
    
                            if(ds.findParent(node) != ds.findParent(newNode))
                            {
                                ds.unionBySize(node, newNode);
                            }
                        }
                    }
                }
            }

            int ans = 0;

            for(int row = 0; row < n; row++)
            {
                for(int col = 0; col < m; col++)
                {
    
                    if(grid[row][col] == 1) continue;
    
                    int node = row * n + col;

                    set<int> component;
    
                    for(int i = 0; i < 4; i++)
                    {
                        int nRow = delRow[i] + row;
                        int nCol = delCol[i] + col;
    
                        if(isValid(nRow, nCol, n, m) && grid[nRow][nCol])
                        {
                            int newNode = nRow * n + nCol;

                            component.insert(ds.findParent(newNode));
                        }
                    }

                    int sizeTotal = 0;

                    for(int x : component)
                    {
                        sizeTotal = sizeTotal + ds.size[x];
                    }

                    ans = max(ans, sizeTotal + 1);
                }
            }


            for(int i = 0; i < n*m; i++)
            {
                if(ds.parent[i] == i) ans = max(ans, ds.size[i]);
            }

            return ans;
        }
    };