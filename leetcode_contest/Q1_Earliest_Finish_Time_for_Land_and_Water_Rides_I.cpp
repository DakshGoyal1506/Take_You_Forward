#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

            int n = landStartTime.size();
            int m = waterStartTime.size();

            int ans = INT_MAX;

            for(int i = 0; i < n; i++)
            {
                int landTime = landStartTime[i] + landDuration[i];

                for(int j = 0; j < m; j++)
                {
                    int waterTime = waterStartTime[j] + waterDuration[j];
                    int finish_1 = max(landTime, waterStartTime[j]) + waterDuration[j];
                    int finish_2 = max(waterTime, landStartTime[i]) + landDuration[i];

                    ans = min({ans, finish_1, finish_2});
                }
            }
            return ans;
        }
    };