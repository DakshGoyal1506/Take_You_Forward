#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n = gain.size();
        vector<int> arr(n+1, 0);

        for(int i = 1; i <= n; i++)
        {
            arr[i] = arr[i-1] + gain[i-1];
        }

        return *max_element(arr.begin(), arr.end());
    }
};