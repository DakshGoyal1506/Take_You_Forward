#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string predictPartyVictory(string senate) {

            queue<int> r, d;
            int n = senate.size();

            for(int i = 0; i < n; i++)
            {
                if(senate[i] == 'R') r.push(i);
                else d.push(i);
            }

            while(!r.empty() && !d.empty())
            {
                int x = r.front();
                int y = d.front();
                r.pop();
                d.pop();

                if(x < y) r.push(x + n);
                else d.push(y + n);
            }

            return !r.empty() ? "Radiant" : "Dire";
        }
    };