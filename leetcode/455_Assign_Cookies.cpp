#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {

            int n = g.size();
            int m = s.size();

            sort(g.begin(), g.end());
            sort(s.begin(), s.end());

            int cookie = 0, child = 0;

            while(cookie < n && child < m)
            {
                if(g[cookie] >= s[child])
                {
                    child++;
                }
                cookie++;
            }

            return child;
            
        }
    };