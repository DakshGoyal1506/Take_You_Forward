#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<long long> topprefix(n+1, 0), bottomprefix(n+1, 0);

        int result = LLONG_MAX;

        for(int i = 0; i < n; i++)
        {
            topprefix[i+1] = topprefix[i] + grid[0][i];
            bottomprefix[i+1] = bottomprefix[i] + grid[1][i];
        }

        for(int i = 0; i < n; i++)
        {
            int top_rem = topprefix[n] - topprefix[i+1];
            int bottom_rem = bottomprefix[i];
            int points = max(top_rem, bottom_rem);

            result = min(result, points);
        }

        return result;
    }
};