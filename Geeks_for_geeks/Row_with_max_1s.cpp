#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int lowerBound(vector<int>& arr, int n)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while(low <= high)
        {
            int mid = (low + high)/2;
            if(arr[mid] == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int count = 0;
        int index = -1;

        for(int i = 0; i < n; i++)
        {
            int val = m - lowerBound(arr[i], m);
            if(count < val)
            {
                index = i;
                count = val;
            }
        }

        return index;
    }
};