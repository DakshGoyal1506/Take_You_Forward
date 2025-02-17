#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {

            int n = intervals.size();
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> ans;
            ans.push_back(intervals[0]);

            for(int i = 1; i < n; i++)
            {
                int m = ans.size();
                if(ans[m-1][1] >= intervals[i][0])
                {
                    vector<int> temp = {min(ans[m-1][0], intervals[i][0]), max(ans[m-1][1], intervals[i][1])};
                    ans.pop_back();
                    ans.push_back(temp);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }

            return ans;
            
        }
    };