#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {

            vector<int> arr(26, 0);

            int maxCount = 0;

            for(char c : tasks)
            {
                int x = c-'A';
                arr[x]++;
                maxCount = max(maxCount, arr[x]);
            }

            int taskCount = 0;

            for(int x : arr)
            {
                if(x == maxCount) taskCount++;
            }

            int ans = (maxCount - 1) * (n + 1) + taskCount;

            return max(static_cast<int>(tasks.size()), ans);
            
        }
    };