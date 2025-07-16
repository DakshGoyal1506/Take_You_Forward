#include <bits/stdc++.h>
using namespace std;

class Solution{

    private:
        void dfs(int node, vector<bool>& visited, vector<int> adj[], stack<int>& st)
        {
            visited[node] = 1;
            for(auto x : adj[node])
            {
                if(!visited[x]) dfs(x, visited, adj, st);
            }

            st.push(node);
        }

        void Helperdfs(int node, vector<bool>& visited, vector<int> adjR[])
        {
            visited[node] = 1;
            for(auto x : adjR[node])
            {
                if(!visited[x]) Helperdfs(x, visited, adjR);
            }
        }
    public:
        int kosaraju(int V, vector<int> adj[]){

            vector<bool> visited(V, false);
            stack<int> st;

            for(int i = 0; i < V; i++)
            {
                if(!visited[i])
                {
                    dfs(i, visited, adj, st);
                }
            }

            vector<int> adjR[V];
            // visited.assign(V, false);

            for(int i = 0; i < V; i++)
            {
                visited[i] = 0;
                for(auto x: adj[i])
                {
                    adjR[x].push_back(i);
                }
            }

            int count = 0;

            while(!st.empty())
            {
                int node = st.top();
                st.pop();

                if(!visited[node])
                {
                    count++;
                    Helperdfs(node, visited, adjR);
                }
            }
            return count;
        }
    };
    