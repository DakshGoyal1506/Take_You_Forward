#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        void topological(int src, vector<pair<int, int>> adj[],
                        vector<bool>& visited, stack<int>& st)
        {
            visited[src] = true;

            for(auto &x : adj[src])
            {
                int node = x.first;
                if(!visited[node])
                {
                    topological(node, adj, visited, st);
                }
            }

            st.push(src);
        }
    public:
        vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

            vector<pair<int,int>> adj[N];

            for(int i = 0; i < M; i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];

                adj[u].push_back({v,wt});
            }

            vector<int> dist(N, INT_MAX);
            vector<bool> visited(N, false);
            stack<int> st;

            for(int i = 0; i < N; i++)
            {
                if(!visited[i]) topological(i, adj, visited, st);
            }

            dist[0] = 0;

            while(!st.empty())
            {
                int node = st.top();
                st.pop();

                if(dist[node] == INT_MAX) continue;

                for(auto &x: adj[node])
                {
                    int v = x.first;
                    int wt = x.second;

                    dist[v] = min(dist[v], dist[node] + wt);
                }
            }

            for(int i = 0; i < N; i++)
            {
                if(dist[i] == INT_MAX) dist[i] = -1;
            }

            return dist;
        }
};

