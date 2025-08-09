#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int ans = 0;

        for(int x : nums)
        {
            if(mp[k - x])
            {
                ans++;
                mp[k-x]--;
                continue;
            }
            else
            {
                mp[x]++;
            }
        }
        return ans;
    }
};