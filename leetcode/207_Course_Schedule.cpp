#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> topologicalSort(int numCourses, vector<int> adj[])
        {
            vector<int> ans;
            vector<int> inDegree(numCourses, 0);

            for(int i = 0; i < numCourses; i++)
            {
                for(auto x: adj[i]) inDegree[x]++;
            }

            queue<int> q;
            
            for(int i = 0; i < numCourses; i++) 
            {
                if(inDegree[i] == 0) q.push(i);
            }

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto x : adj[node])
                {
                    if(-- inDegree[x] == 0) q.push(x);
                }
            }
            return ans;
        }
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

            vector<int> adj[numCourses];

            for(vector<int> x : prerequisites)
            {
                adj[x[1]].push_back(x[0]);
            }
            vector<int> ans = topologicalSort(numCourses, adj);

            return (ans.size() < numCourses) ? false : true;
        }
    };