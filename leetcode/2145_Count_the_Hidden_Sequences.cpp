#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         int numberOfArrays(vector<int>& differences, int lower, int upper) {

//             int range = 0;
//             int sum = differences[0];
//             int n = differences.size();

//             for(int i = 1; i < n; i++)
//             {
//                 if(differences[i] < 0 && differences[i-1] < 0)
//                 {
//                     sum = sum + differences[i];
//                 }
//                 else if(differences[i] >= 0 && differences[i-1] >= 0)
//                 {
//                     sum = sum + differences[i];
//                 }
//                 else
//                 {
//                     sum = abs(sum);
//                     if(sum > range)
//                     {
//                         range = sum;
//                     }
//                     sum = differences[i];
//                 }
//             }

//             sum = abs(sum);
//             if(sum > range)
//             {
//                 range = sum;
//             }
        
//             int ans = (upper - lower + 1) - range;

//             if(ans > 0)
//             {
//                 return ans;
//             }
//             else
//             {
//                 return 0;
//             }
            
//         }
//     };

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
    
            long long prefix = 0, min_prefix = 0, max_prefix = 0;
            for (int diff : differences) {
                prefix += diff;
                min_prefix = min(min_prefix, prefix);
                max_prefix = max(max_prefix, prefix);
            }
    
            long long range = max_prefix - min_prefix;
            long long ans = (long long)upper - lower - range + 1;
            return ans < 0 ? 0 : ans;
        }
    };