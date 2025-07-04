#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int,int>>

class Solution
{

    private:
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};

        bool isValid(int i, int j, int n, int m)
        {
            if(i < 0 || i >= n) return false;
            if(j < 0 || j >= m) return false;
            return true;
        }
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {

            int n = heights.size();
            int m = heights[0].size();

            vector<vector<int>> maxDist(n, vector<int>(m, 1e9));

            maxDist[0][0] = 0;

            priority_queue<P, vector<P>, greater<P>> pq;

            pq.push({0, {0, 0}});

            while(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                int diff = it.first;

                int row = it.second.first;
                int col = it.second.second;

                if(row == n - 1 && col == m - 1) return diff;

                for(int i = 0; i < 4; i++)
                {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if(isValid(nrow, ncol, n, m))
                    {
                        int ndiff = abs(heights[row][col] - heights[nrow][ncol]);

                        if(max(diff, ndiff) < maxDist[nrow][ncol])
                        {
                            maxDist[nrow][ncol] = max(diff, ndiff);
                            pq.push({maxDist[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }
            return -1;
        }
    };