#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        void bfs(int node, vector<int> edges[], int vis[])
        {
            queue<int> q;
            q.push(node);

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int x: edges[node])
                {
                    if(vis[x] == 0)
                    {
                        vis[x] = 1;
                        q.push(x);
                    }
                }

            }
        }
    public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

        int e = edges.size();

        vector<int> adj[V];

        for(int i = 0; i < e; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int vis[V] = {0};
        int ans = 0;

        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                ans++;
                bfs(i, adj, vis);
            }
        }
        return ans;
      
      }
  };