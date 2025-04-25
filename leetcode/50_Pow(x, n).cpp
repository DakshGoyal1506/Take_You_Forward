#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         double myPow(double x, int n) {

//             if(n == 0)
//             {
//                 return 1;
//             }

//             if(n > 0)
//             {
//                 return (x * myPow(x, n-1));
//             }
//             else
//             {
//                 return((1/x) * myPow(x, n + 1));
//             }
            
//         }
//     };

class Solution {
    public:
        double myPow(double x, int n){

            long power = n;

            if(power < 0)
            {
                x = 1 / x;
                power = -power;
            }

            double result = 1;

            while(power)
            {
                if(power & 1)
                {
                    result = result * x;
                }
                x = x * x;
                power >>= 1;
            }

            return result;
        }
    
    };