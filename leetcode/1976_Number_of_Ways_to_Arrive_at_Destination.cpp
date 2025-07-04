#include <bits/stdc++.h>
using namespace std;

#define P pair<long long,int>

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {

            vector<pair<int, int>> adj[n];
            int mod = 1e9 + 7;

            for(auto it: roads)
            {
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }

            vector<long long> dist(n, LONG_LONG_MAX);

            vector<int> ways(n, 0);

            priority_queue<P, vector<P>, greater<P>> pq;

            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0});

            while(!pq.empty())
            {
                auto x = pq.top();
                pq.pop();

                long long dis = x.first;
                int node = x.second;

                for(auto it: adj[node])
                {
                    int v = it.first;
                    int wt = it.second;

                    if(wt + dis < dist[v])
                    {
                        dist[v] = dis + wt;
                        ways[v] = ways[node];
                        pq.push({dist[v], v});
                    }
                    else if(wt + dis == dist[v])
                    {
                        ways[v] = (ways[v] + ways[node]) % mod;
                    }
                }
            }
            return ways[n-1] % mod;
        }
    };