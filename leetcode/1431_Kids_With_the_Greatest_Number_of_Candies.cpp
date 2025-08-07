#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int element = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for(int x : candies)
        {
            if((x + extraCandies) >= element) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};