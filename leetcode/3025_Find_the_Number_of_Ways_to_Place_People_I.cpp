#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int ans = 0;
        int n = points.size();

        for(int i = 0; i < n - 1; i++)
        {
            int xi = points[i][0], yi = points[i][1];
            
            for(int j = i + 1; j < n; j++)
            {
                int xj = points[j][0], yj = points[j][1];

                if (xi <= xj && yi >= yj) 
                {
                    bool empty = true;

                    for (int k = 0; k < n; ++k) 
                    {
                        if (k == i || k == j) continue;
                        
                        int x = points[k][0], y = points[k][1];

                        if (xi <= x && x <= xj && yj <= y && y <= yi) 
                        {
                            empty = false;
                            break;
                        }
                    }

                    if (empty) ++ans;
                }
            }
        }

        return ans;
        
    }
};