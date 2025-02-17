#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<int> leaders(vector<int>& arr){
        int n = arr.size();
        int maxElement = 0;
        vector<int> ans;

        for(int i = n - 1; i >= 0; i--)
        {
            if(arr[i] >= maxElement)
            {
                ans.push_back(arr[i]);
                maxElement = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};