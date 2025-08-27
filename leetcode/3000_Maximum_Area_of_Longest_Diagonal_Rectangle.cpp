#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int diagonal = -1, area = 0;
        int n = dimensions.size();

        for(int i = 0; i < n; i++)
        {
            int l = dimensions[i][0], b = dimensions[i][1];
            int temp = l*l + b*b;
            if(temp > diagonal)
            {
                diagonal = temp;
                area = l * b;
            }
            else if(temp == diagonal)
            {
                area = max(area, l*b);
            }
        }
        return area;
    }
};
