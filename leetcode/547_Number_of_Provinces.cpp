#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void bfs(int node, vector<vector<int>>& isConnected,vector<int>& vis)
        {
            queue<int> q;
            q.push(node);
            int n = isConnected[0].size();

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int i = 0; i < n; i++)
                {
                    if(isConnected[node][i] == 1 && !vis[i])
                    {
                        vis[i] = 1;
                        q.push(i);
                    }
                }

            }
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {

            int n = isConnected.size();
            vector<int> vis(n, 0);

            int ans = 0;

            for(int i = 0; i < n; i++)
            {
                if(vis[i] == 0)
                {
                    vis[i] = 1;
                    ans++;
                    bfs(i, isConnected, vis);
                }
            }
            return ans;
        }
    
  };