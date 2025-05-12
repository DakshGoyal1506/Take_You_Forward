#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

class Solution {
    public:

        long long power(long long base, long long power)
        {
            long long result = 1;

            while(power)
            {
                if(power % 2 == 1)
                {
                    result = (result * base) % MOD;
                    power--;
                }
                else
                {
                    base = (base * base) % MOD;
                    power >>=1;
                }
            }

            return result;
        }

        int countGoodNumbers(long long n) {

            long long even = (n + 1) / 2;
            long long odd = n / 2;

            long long evenresult = power(5, even);
            long long oddresult = power(4, odd);

            return (evenresult * oddresult) % MOD;
            
        }
    };