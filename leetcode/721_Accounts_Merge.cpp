#include <bits/stdc++.h>
using namespace std;

class disSet{
    public:
        vector<int> parent, rank, size;

        disSet(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);

            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findParent(int node)
        {
            return (parent[node] == node) ? node : parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v)
        {
            int uPar_u = findParent(u);
            int uPar_v = findParent(v);

            if(uPar_u == uPar_v) return ;

            if(size[uPar_u] < size[uPar_v])
            {
                parent[uPar_u] = uPar_v;
                size[uPar_v] += size[uPar_u];
            }
            else
            {
                parent[uPar_v] = uPar_u;
                size[uPar_u] += size[uPar_v];
            }
        }
};

class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

            int n = accounts.size();

            disSet ds(n);

            unordered_map<string, int> mp;

            for(int i = 0; i < n; i++)
            {
                for(int j = 1; j < accounts[i].size(); j++)
                {
                    string mail = accounts[i][j];

                    if(mp.find(mail) == mp.end())
                    {
                        mp[mail] = i;
                    }
                    else
                    {
                        ds.unionBySize(i, mp[mail]);
                    }
                }
            }

            vector<string> mergedMail[n];

            for(auto it: mp)
            {
                string mail = it.first;
                int node = ds.findParent(it.second);

                mergedMail[node].push_back(mail);
            }

            vector<vector<string>> ans;

            for(int i = 0; i < n; i++)
            {
                if(mergedMail[i].size() == 0) continue;

                vector<string> temp;
                temp.push_back(accounts[i][0]);
                
                sort(mergedMail[i].begin(), mergedMail[i].end());

                for(auto x : mergedMail[i])
                {
                    temp.push_back(x);
                }
                ans.push_back(temp);
            }

            sort(ans.begin(), ans.end());

            return ans;
            
        }
    };