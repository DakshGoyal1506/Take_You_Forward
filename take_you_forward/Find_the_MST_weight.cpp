#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<bool> visited(V, false);

        int sum = 0;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();

            int node = x.second;
            int wt = x.first;

            if(visited[node]) continue;

            visited[node] = true;

            sum = sum + wt;

            for(auto it : adj[node])
            {
                int v = it[0];
                int edge = it[1];

                if(!visited[v]) pq.push({edge, v});
            }
        }

        return sum;
    }
};
