#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {

        int ans = INT_MAX;

        for(auto& task : tasks)
        {
            int s = task[0];
            int t = task[1];

            ans = min(ans, s+t);
        }
        return ans;
    }
};