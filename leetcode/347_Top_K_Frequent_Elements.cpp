#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {

            unordered_map<int, int> mp;

            for(int x: nums)
            {
                mp[x]++;
            }

            priority_queue<pair<int,int> ,vector<pair<int,int>>> pq;

            for(auto& x: mp)
            {
                pq.push({x.second, x.first});
            }

            vector<int> ans(k);

            for(int i = 0; i < k; i++)
            {
                ans[i] = pq.top().second;
                pq.pop();
            }
            return ans;
            
        }
    };