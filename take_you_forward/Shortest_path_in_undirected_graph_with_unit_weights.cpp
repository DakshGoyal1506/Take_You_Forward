#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void bfs(vector<int> adj[], vector<int>& ans)
        {
            ans[0] = 0;
            queue<int> q;
            q.push(0);

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(auto x : adj[node])
                {
                    if(ans[node] + 1 < ans[x])
                    {
                        ans[x] = ans[node] + 1;
                        q.push(x);
                    }
                }
            }
        }
    public:
        vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){

            vector<int> adj[N];

            for(int i = 0; i < M; i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<int> ans(N, INT_MAX);

            bfs(adj, ans);

            for(int i = 0; i < N; i++)
            {
                if(ans[i] == INT_MAX) ans[i] = -1;
            }
        
            return ans;
        }
    };
