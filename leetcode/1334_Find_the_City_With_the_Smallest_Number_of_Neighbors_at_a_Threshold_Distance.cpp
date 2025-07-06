#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

            vector<vector<int>> adj(n, vector<int>(n, 1e9));

            for(auto it: edges)
            {
                adj[it[0]][it[1]] = it[2];
                adj[it[1]][it[0]] = it[2];
            }

            for(int k = 0; k < n; k++)
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }

            int ans = -1;
            int minCount = 1e9;

            for(int i = 0; i < n; i++)
            {
                int count = 0; 

                for(int j = 0; j < n; j++)
                {
                    if(i != j && adj[i][j] <= distanceThreshold) count++;
                }

                if(count < minCount)
                {
                    minCount = count;
                    ans = i;
                }
                else if(count == minCount)
                {
                    ans = i;
                }
            }
            return ans;
        }
    };