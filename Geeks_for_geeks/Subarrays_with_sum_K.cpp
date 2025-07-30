#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int cntSubarrays(vector<int> &arr, int k) {
            // code here

            unordered_map<int, int> prefix;
            prefix[0] = 1;
            int sum = 0, count = 0;

            for(int x : arr)
            {
                sum = sum + x;
                if(prefix.count(sum - k)) count = count + prefix[sum - k];
                prefix[sum]++;
            }
            return count;
        }
  };