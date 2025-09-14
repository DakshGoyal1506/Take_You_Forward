#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        long long log4(long long x)
        {
            return log(x) / log(4);
        }
    public:
        long long minOperations(vector<vector<int>>& queries) {

            long long ans = 0;
            int n = queries.size();

            for(int i = 0; i < n; i++)
            {
                long long a = queries[i][0];
                long long b = queries[i][1];
                long long temp = 0;

                // for(int j = a; j <= b; j++)
                // {
                //     temp = temp + log4(j) + 1;
                // }

                long long pow = 1;
                long long k = 0;

                while(pow <= b)
                {
                    long long next = pow * 4;
                    long long L = max(a, pow);
                    long long R = min(b, next - 1);

                    if(R >= L)
                    {
                        long long count = R - L + 1;
                        temp = temp + count * (k + 1);
                    }
                    pow = next;
                    k++;
                }
                ans = ans + (temp + 1) / 2;
            }
            return ans;
        }
};