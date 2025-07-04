#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {

            n = n + 1;

            vector<P> adj[n];

            for(auto it: times)
            {
                adj[it[0]].push_back({it[1], it[2]});
            }

            priority_queue<P, vector<P>, greater<P>> pq;

            vector<int> dist(n, 1e9);
            dist[k] = 0;
            pq.push({0, k});

            while(!pq.empty())
            {
                auto x = pq.top();
                pq.pop();

                int dis = x.first;
                int node = x.second;

                for(auto it: adj[node])
                {
                    int v = it.first;
                    int wt = it.second;

                    if(dis + wt < dist[v])
                    {
                        dist[v] = dis + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            int ans = -1;
            
            for(int i = 1; i < n; i++)
            {
                if(dist[i] == 1e9) return -1;
                
                ans = max(ans, dist[i]);
            }
            return ans;
        }
    };