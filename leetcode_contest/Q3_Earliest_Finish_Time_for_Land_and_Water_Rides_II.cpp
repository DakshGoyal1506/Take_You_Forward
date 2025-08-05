#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                               vector<int>& waterStartTime, vector<int>& waterDuration) {
            
            auto hasturvane = make_tuple(landStartTime, landDuration, waterStartTime, waterDuration);

            int n = landStartTime.size(), m = waterStartTime.size();

            
            vector<pair<int,int>> waters(m);
            for(int j = 0; j < m; j++) 
                waters[j] = {waterStartTime[j], waterDuration[j]};
            sort(waters.begin(), waters.end());

            // build prefix min‐durations for water rides
            vector<int> waterPrefixDur(m);
            waterPrefixDur[0] = waters[0].second;
            for(int i = 1; i < m; i++)
                waterPrefixDur[i] = min(waterPrefixDur[i-1], waters[i].second);

            vector<int> waterSuffix(m);
            waterSuffix[m-1] = waters[m-1].first + waters[m-1].second;
            for(int i = m-2; i >= 0; i--)
                waterSuffix[i] = min(waterSuffix[i+1],
                                     waters[i].first + waters[i].second);

        
            vector<pair<int,int>> lands(n);
            for(int i = 0; i < n; i++)
                lands[i] = {landStartTime[i], landDuration[i]};
            sort(lands.begin(), lands.end());

            // build prefix min‐durations for land rides
            vector<int> landPrefixDur(n);
            landPrefixDur[0] = lands[0].second;
            for(int i = 1; i < n; i++)
                landPrefixDur[i] = min(landPrefixDur[i-1], lands[i].second);

            vector<int> landSuffix(n);
            landSuffix[n-1] = lands[n-1].first + lands[n-1].second;
            for(int i = n-2; i >= 0; i--)
                landSuffix[i] = min(landSuffix[i+1],
                                    lands[i].first + lands[i].second);

            int ans = INT_MAX;

            // land -> water
            for(int i = 0; i < n; i++) {
                int t = landStartTime[i] + landDuration[i];
                int idx = lower_bound(waters.begin(), waters.end(),
                                      pair<int,int>{t,0}) - waters.begin();
                int finish = INT_MAX;
                if(idx > 0)  // rides already open
                    finish = t + waterPrefixDur[idx-1];
                if(idx < m) // rides opening later
                    finish = min(finish, waterSuffix[idx]);
                ans = min(ans, finish);
            }

            // water -> land
            for(int j = 0; j < m; j++) {
                int t = waterStartTime[j] + waterDuration[j];
                int idx = lower_bound(lands.begin(), lands.end(),
                                      pair<int,int>{t,0}) - lands.begin();
                int finish = INT_MAX;
                if(idx > 0)
                    finish = t + landPrefixDur[idx-1];
                if(idx < n)
                    finish = min(finish, landSuffix[idx]);
                ans = min(ans, finish);
            }

            return ans;
        }
};

nb9xd9rp