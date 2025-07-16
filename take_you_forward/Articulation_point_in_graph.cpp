#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        int time = 1;

        void dfs(int node, int parent, vector<bool>& visited,
                vector<int> adj[], vector<int>& dis, vector<int>& low,
                vector<bool>& mark)
        {
            visited[node] = 1;
            dis[node] = low[node] = time;

            time ++;

            int child = 0;

            for(auto x : adj[node])
            {
                if(x == parent) continue;

                if(!visited[x])
                {
                    dfs(x, node, visited, adj, dis, low, mark);

                    low[node] = min(low[x], low[node]);

                    if(low[x] >= dis[node] && parent != -1) mark[node] = 1;

                    child++;
                }
                else low[node] = min(dis[x], low[node]);
            }

            if(child > 1 && parent == -1) mark[node] = 1;
        }
    public:
        vector<int> articulationPoints(int n, vector<int>adj[]) {

            vector<bool> visited(n, 0);
            vector<int> dis(n);
            vector<int> low(n);
            vector<bool> mark(n, 0);

            for(int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    dfs(i, -1, visited, adj, dis, low, mark);
                }
            }

            vector<int> ans;
        
            for (int i = 0; i < n; i++) {
                
                if (mark[i] == 1) {
                    ans.push_back(i);
                }
            }
            
            if (ans.size() == 0) return { -1};

            return ans;
        }
    };