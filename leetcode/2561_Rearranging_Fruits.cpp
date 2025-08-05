#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long minCost(vector<int>& basket1, vector<int>& basket2) {

            unordered_map<int, int> mp;
            int n = basket1.size();

            for(int i = 0; i < n; i++)
            {
                mp[basket1[i]]++;
                mp[basket2[i]]--;
            }

            vector<int> diff;
            int minFruit = INT_MAX;

            for(auto& x : mp)
            {
                if (x.second % 2 != 0) return -1;
                int cnt = abs(x.second) / 2;
                while (cnt--) diff.push_back(x.first);
                minFruit = min(minFruit, x.first);
            }

            sort(diff.begin(), diff.end());
            long long total = 0;
            int m = diff.size();
            for(int i = 0; i < m/2; i++)
                total += min<long long>(diff[i], 2LL * minFruit);
            return total;
        }
    };