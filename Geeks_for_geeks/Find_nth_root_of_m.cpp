#include <iostream>
using namespace std;

class Solution {
    public:

    int foo(int n, int m, int mid)
    {
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            ans = ans * mid;
            if(ans > m)
            {
                return 0;
            }
        }

        if(ans == m)
        {
            return 1;
        }

        if (ans < m)
        {
            return 2;
        }
    }

    int nthRoot(int n, int m) {
        // Code here.
        int low = 0, high = m;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            int num = foo(n, m, mid);

            if(num == 1)
            {
                return mid;
            }

            if(num == 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};