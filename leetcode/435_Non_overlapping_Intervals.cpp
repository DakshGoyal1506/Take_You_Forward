#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

        bool static compare(const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b [1];
        }

        int eraseOverlapIntervals(vector<vector<int>>& intervals) {

            sort(intervals.begin(), intervals.end(), compare);

            int n = intervals.size();

            int count = 1;
            int lasttime = intervals[0][1];

            for(int i = 1; i < n; i++)
            {
                if(intervals[i][0] >= lasttime)
                {
                    count++;
                    lasttime = intervals[i][1];
                }
            }

            return n - count;
            
        }
    };