#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings){

        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        vector<pair<int, int>> merged;

        int currentstart = meetings[0][0];
        int currentend = meetings[0][1];

        for(int i = 1; i < meetings.size(); i++)
        {
            int start = meetings[i][0], end = meetings[i][1];
            if (start <= currentend + 1)
            {
                currentend = max(currentend, end);
            }
            else
            {
                merged.push_back({currentstart, currentend});
                currentstart = start;
                currentend = end;
            }
        }

        merged.push_back({currentstart, currentend});
        
        long long meetingdays = 0;

        for(auto& interval : merged)
        {
            meetingdays = meetingdays + (interval.second - interval.first + 1);
        }

        return days - meetingdays;
    }
};

// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {

//         vector<bool> hasmeeting(days + 1, false);

//         for(auto& meeting : meetings)
//         {
//             for(int day = meeting[0]; day <= meeting[1]; day++)
//             {
//                 hasmeeting[day] = true;
//             }
//         }

//         int ans = 0;

//         for(int i = 1; i <= days; i++)
//         {
//             if(!hasmeeting[i])
//             {
//                 ans++;
//             }
//         }

//         return ans;
        
//     }
// };