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
    public:
        int removeStones(vector<vector<int>>& stones) {

            int n = stones.size();

            int maxRows = 0;
            int maxCols = 0;

            for(auto it : stones)
            {
                maxRows = max(maxRows, it[0]);
                maxCols = max(maxCols, it[1]);
            }

            disSet ds(maxRows + maxCols + 1);

            unordered_set<int> st;

            for(auto it: stones)
            {
                int row = it[0];
                int col = it[1] + maxRows + 1;

                ds.unionBySize(row, col);

                st.insert(row);
                st.insert(col);
            }

            int k = 0;

            for(int x : st)
            {
                if(ds.findParent(x) == x) k++;
            }

            return n - k;
            
        }
    };