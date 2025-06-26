#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        bool isValid(int i, int j, int m, int n)
        {
            if(i < 0 || i >= m) return false;
            if(j < 0 || j >= n) return false;
            return true;
        }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

            int m = image.size();
            int n = image[0].size();
            queue<pair<int, int>> q;
            q.push({sr, sc});
            int start_color = image[sr][sc];
            image[sr][sc] = color;

            if(start_color == color) return image;

            while(!q.empty())
            {
                auto x = q.front();
                q.pop();

                int row0 = x.first;
                int col0 = x.second;

                for(int i = 0; i < 4; i++)
                {
                    int row = row0 + delRow[i];
                    int col = col0 + delCol[i];

                    if(isValid(row, col, m, n) && image[row][col] == start_color)
                    {
                        image[row][col] = color;
                        q.push({row, col});
                    }
                }
            }

            return image;
            
        }
    };