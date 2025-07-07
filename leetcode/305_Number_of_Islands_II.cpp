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

class Solution{

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
        vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){

            disSet ds(n*m);

            vector<vector<int>> visited(n, vector<int>(m, 0));
            vector<int> ans;

            int count = 0;

            for(auto it: A)
            {
                int row = it[0];
                int col = it[1];

                if(visited[row][col])
                {
                    ans.push_back(count);
                    continue;
                }

                visited[row][col] = 1;

                count++;

                for(int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(isValid(nRow, nCol, n, m) && visited[nRow][nCol])
                    {
                        int node = row * m + col;
                        int newNode = nRow * m + nCol;

                        if(ds.findParent(node) != ds.findParent(newNode))
                        {
                            count--;
                            ds.unionBySize(node, newNode);
                        }
                    }
                }
                ans.push_back(count);
            }
            return ans;
        }
    };