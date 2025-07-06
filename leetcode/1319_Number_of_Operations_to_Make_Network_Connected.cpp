#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:

        vector<int> parent, rank, size;

        DisjointSet(int n) {

            parent.resize(n+1, 0);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
         
        }
    
        bool findParent(int node) {
            return (parent[node] == node) ? node : parent[node] = findParent(parent[node]);
        }
    
        void unionByRank(int u, int v) {

            int uPar_u = findParent(u);
            int uPar_v = findParent(v);

            if(uPar_u == uPar_v) return;

            if(rank[uPar_u] < rank[uPar_v])
            {
                parent[uPar_u] = uPar_v;
            }
            else if(rank[uPar_u] > rank[uPar_v]) parent[uPar_v] = uPar_u;
            else
            {
                parent[uPar_v] = uPar_u;
                rank[uPar_u]++;
            }
         
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

class Solution{
    public:
    
        int makeConnected(int n, vector<vector<int>> &Edge){
            
            int size = Edge.size();
            
            if(size < n-1) return -1;
            
            DisjointSet ds(n);
            
            for(int i=0; i<size; i++) {
                ds.unionByRank(Edge[i][0], Edge[i][1]);
            }
            
            int count = 0;
            
            for(int i=0; i<n; i++) {
                if(ds.parent[i] == i) count++;
            }
            
            return count-1;
        }
    };