#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int n = graph.size();
        vector<int> state(n, 0);

        function<bool(int)> dfs = [&](int node)
        {
            if(state[node] == 1) return false;
            if(state[node] == 2) return true;

            state[node] = 1;
            for(int neigh : graph[node])
            {
                if(!dfs(neigh))
                {
                    return false;
                }
            }

            state[node] = 2;
            return true;
        };

        for(int i = 0; i < n; i++)
        {
            if(dfs(i))
            {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());

        return result;
        
    }
};