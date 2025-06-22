#include <bits/stdc++.h>
using namespace std;

class Solution{  
    public:  

        bool static compare(const vector<int>& a, const vector<int>& b)
        {
            return a[2] > b[2];
        }

        vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
            //your code goes here
            sort(Jobs.begin(), Jobs.end(), compare);

            int n = Jobs.size();

            int count = 0;
            int profit = 0;
            int maxdeadline = -1;

            for(auto job: Jobs)
            {
                maxdeadline = max(maxdeadline, job[1]);
            }

            vector<int> ans(maxdeadline + 1, -1);

            for(int i = 0; i < n; i++)
            {
                for(int j = Jobs[i][1]; j >= 0; j--)
                {
                    if(ans[j] == -1)
                    {
                        ans[j] = Jobs[i][0];
                        count++;
                        profit = profit + Jobs[i][2];
                        break;
                    }
                }
            }

            return {count, profit};
        } 
  };