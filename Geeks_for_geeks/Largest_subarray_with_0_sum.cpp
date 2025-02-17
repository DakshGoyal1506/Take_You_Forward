#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxIndex = 0;
        int sum = 0;
        unordered_map <int, int> hash;

        for(int i = 0; i < n; i++)
        {
            sum = sum + arr[i];

            if(sum == 0)
            {
                maxIndex = i + 1;
            }

            if(hash.find(sum) != hash.end())
            {
                maxIndex = max(maxIndex, i - hash[sum]);
            }

            if(hash.find(sum) == hash.end())
            {
                hash[sum] = i;
            }
        }

        return maxIndex;
    }
};