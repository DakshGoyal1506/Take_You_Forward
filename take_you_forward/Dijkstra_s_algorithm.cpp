#include <bits/stdc++.h>
using namespace std;

// class Solution{

//     private:
//         void topodfs(int src, vector<pair<int,int>> edges[], vector<bool>& visited, stack<int>& st)
//         {
//             visited[src] = true;

//             for(auto& x : edges[src])
//             {
//                 int v = x.first;
//                 if(!visited[v]) topodfs(v, edges, visited, st);
//             }
//             st.push(src);
//         }
//     public:
//         vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

//             vector<pair<int,int>> edges[V];

//             for(int i = 0; i < V; i++)
//             {
//                 for(auto x : adj[i])
//                 {
//                     int v = x[0];
//                     int wt = x[1];

//                     edges[i].push_back({v, wt});
//                 }
//             }

//             vector<bool> visited(V, false);
//             stack<int> st;

//             topodfs(S, edges, visited, st);

//             vector<int> dist(V, 1e9);

//             dist[S] = 0;

//             while(!st.empty())
//             {
//                 int node = st.top();
//                 st.pop();

//                 if(dist[node] == 1e9) continue;

//                 for(auto & x : edges[node])
//                 {
//                     int v = x.first;
//                     int wt = x.second;

//                     dist[v] = min(dist[v], dist[node] + wt);
//                 }
//             }
//             return dist;
//         }
//     };

#define P pair<int,int>

class Solution{
    public:
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

            priority_queue<P, vector<P>, greater<P>> pq;
            vector<int> dist(V, 1e9);
            dist[S] = 0;

            pq.push({0, S});

            while(!pq.empty())
            {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for(auto x : adj[node])
                {
                    int v = x[0];
                    int wt = x[1];

                    if(dis + wt < dist[v])
                    {
                        dist[v] = dis + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        }
    };