#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int, int>>

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

            vector<pair<int,int>> adj[n];

            for(auto it : flights)
            {
                adj[it[0]].push_back({it[1], it[2]});
            }

            vector<int> dist(n, 1e9);

            queue<P> q;
            dist[src] = 0;

            q.push({0, {0, src}});

            while(!q.empty())
            {
                auto x = q.front();
                q.pop();

                int steps = x.first;
                int dis = x.second.first;
                int node = x.second.second;

                if(steps > k) continue;

                for(auto x : adj[node])
                {
                    int v = x.first;
                    int wt = x.second;

                    if(dis + wt < dist[v] && steps <= k)
                    {
                        dist[v] = dis + wt;
                        q.push({steps+1, {dist[v], v}});
                    }
                }
            }
            
            for(int i = 0; i < n; i++)
            {
                if(dist[i] == 1e9) dist[i] = -1;
            }

            return dist[dst];
        }
    };