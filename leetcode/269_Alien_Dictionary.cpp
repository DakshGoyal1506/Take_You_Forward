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
        string findOrder(string dict[], int N, int K) {

            vector<int> adj[K];

            for(int i = 0; i < N - 1; i++)
            {
                // for(int j = 0; j < N; j++)
                // {
                //     int m = min(dict[i].size(), dict[j].size());
                //     for(int k = 0; k < m; k++)
                //     {
                //         if(dict[i][k] != dict[j][k]) adj[dict[i][k] - 'a'].push_back(dict[j][k]-'a');

                //     }
                // }
                string &s1 = dict[i];
                string &s2 = dict[i + 1];
                int len = min(s1.size(), s2.size());
                
                for (int ptr = 0; ptr < len; ptr++) 
                {    
                    if (s1[ptr] != s2[ptr]) 
                    {
                        adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                        break;
                    }
                }
            }
            
            vector<int> sort = topologicalSort(K, adj);

            string ans;

            // for(int x : sort)
            // {
            //     ans.push_back(x + 'a');
            // }
            for(int i=0; i < K; i++) 
            {
                ans.push_back(char('a' + sort[i]));
                ans.push_back(' ');
            }

            return ans;
        }
    };