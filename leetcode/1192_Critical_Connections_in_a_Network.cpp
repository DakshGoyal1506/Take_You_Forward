#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int time = 1;

        void dfs(int node, int parent, vector<bool>& visited,
                vector<int> adj[], vector<int>& dis, vector<int>& low,
                vector<vector<int>>& bridges)
        {
            visited[node] = 1;
            dis[node] = low[node] = time;

            time ++;

            for(auto x : adj[node])
            {
                if(x == parent) continue;

                if(!visited[x])
                {
                    dfs(x, node, visited, adj, dis, low, bridges);

                    low[node] = min(low[x], low[node]);

                    if(low[x] > dis[node]) bridges.push_back({x, node});
                }
                else low[node] = min(low[x], low[node]);
            }
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

            vector<bool> visited(n, false);
            vector<int> adj[n];

            for(auto x : connections)
            {
                int u = x[0], v = x[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<int> dis(n);
            vector<int> low(n);
            vector<vector<int>> bridges;

            dfs(0, -1, visited, adj, dis, low, bridges);
            
            return bridges;
        }
    };