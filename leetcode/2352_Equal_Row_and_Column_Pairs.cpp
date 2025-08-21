#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> transpose(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                transpose[i][j] = grid[j][i];
            }
        }

        int ans = 0;

        for(auto& i: grid)
        {
            for(auto& j: transpose)
            {
                ans = ans + (i == j);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {

//         int n = grid.size();
//         struct VectorHash {
//             size_t operator()(const vector<int>& v) const {
//                 size_t hash = 0;
//                 for (int num : v) {
//                     hash ^= hash * 31 + std::hash<int>()(num);
//                 }
//                 return hash;
//             }
//         };

//         unordered_map<vector<int>, int, VectorHash> mp;

//         for(int i = 0; i < n; i++)
//         {
//             mp[grid[i]]++;
//         }
        
//     }
// };