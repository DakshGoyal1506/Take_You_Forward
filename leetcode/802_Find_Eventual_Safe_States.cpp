// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional>
// using namespace std;

// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         vector<int> result;
//         int n = graph.size();
//         vector<int> state(n, 0);

//         function<bool(int)> dfs = [&](int node)
//         {
//             if(state[node] == 1) return false;
//             if(state[node] == 2) return true;

//             state[node] = 1;
//             for(int neigh : graph[node])
//             {
//                 if(!dfs(neigh))
//                 {
//                     return false;
//                 }
//             }

//             state[node] = 2;
//             return true;
//         };

//         for(int i = 0; i < n; i++)
//         {
//             if(dfs(i))
//             {
//                 result.push_back(i);
//             }
//         }

//         sort(result.begin(), result.end());

//         return result;
        
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        bool dfs(int node, vector<vector<int>>& graph, vector<int>& state)
        {
            if(state[node] == 1) return false;
            if(state[node] == 2) return true;

            state[node] = 1;

            for(int x : graph[node])
            {
                if(!dfs(x, graph, state)) return false;
            }

            state[node] = 2;
            return true;
        }
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

            int n = graph.size();
            vector<int> ans;
            vector<int> state(n, 0);

            for(int i = 0; i < n; i ++)
            {
                if(dfs(i, graph, state)) ans.push_back(i);
            }
            return ans;
        }
    };