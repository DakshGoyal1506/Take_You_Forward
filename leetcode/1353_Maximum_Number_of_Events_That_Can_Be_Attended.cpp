#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) {

            unordered_map<int, vector<int>> event;

            int minDay = INT_MAX;
            int maxDay = 0;

            for(auto x : events)
            {
                int startDay = x[0];
                int endDay = x[1];

                event[startDay].push_back(endDay);

                minDay = min(minDay, startDay);
                maxDay = max(maxDay, endDay);
            }

            priority_queue<int, vector<int>, greater<int>> pq;

            int ans = 0;

            for(int day = minDay; day <= maxDay; day++)
            {
                while(!pq.empty() && pq.top() < day) pq.pop();

                for(int end : event[day])
                {
                    pq.push(end);
                }

                if(!pq.empty())
                {
                    ans++;
                    pq.pop();
                }
            }
            return ans;
        }
    };