#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowcount(m, 0);
        vector<int> coloumncount(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]==1)
                {
                    rowcount[i]++;
                    coloumncount[j]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]==1 && (rowcount[i] > 1 || coloumncount[j] > 1))
                {
                    ans++;
                }
            }
        }

        return ans;

    }
};