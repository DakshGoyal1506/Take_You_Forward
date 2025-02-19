#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
    public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int n = arr.size();
        int floor = -1, ceil = -1;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] == x)
            {
                return {x, x};
            }
            else if(arr[i] < x)
            {
                if(floor == -1)
                {
                    floor = arr[i];
                }
                floor = max(floor, arr[i]);
            }
            else{
                if(ceil == -1)
                {
                    ceil = arr[i];
                }
                ceil = min(ceil, arr[i]);
            }
        }

        return {floor, ceil};
    }
};