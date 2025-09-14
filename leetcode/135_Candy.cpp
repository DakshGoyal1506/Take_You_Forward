#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         int candy(vector<int>& ratings) {

//             int val = 1;
//             int n = ratings.size();

//             vector<int> left(n, 1), right(n,1);

//             for(int i = 1; i < n; i++)
//             {
//                 if(ratings[i] > ratings[i-1])
//                 {
//                     val++;
//                 }
//                 else
//                 {
//                     val = 1;
//                 }
//                 left[i] = val;
//             }

//             val = 1;

//             for(int i = n - 2; i >= 0; i--)
//             {
//                 if(ratings[i] > ratings[i+1])
//                 {
//                     val++;
//                 }
//                 else 
//                 {
//                     val = 1;
//                 }
//                 right[i] = val;
//             }

//             int ans = 0;

//             for(int i = 0; i < n; i++)
//             {
//                 ans = ans + max(left[i], right[i]);
//             }

//             return ans;
//         }
//     };

class Solution {
    public:
        int candy(vector<int>& ratings) {

            int sum = 1;
            int i = 1;
            int n = ratings.size();

            while(i < n)
            {
                if(ratings[i] == ratings[i-1])
                {
                    sum = sum+1;
                    i++;
                    continue;
                }

                int peak = 1;

                while(i < n && ratings[i] > ratings[i-1])
                {
                    peak++;
                    sum = sum + peak;
                    i++;
                }

                int down = 1;
                while(i < n && ratings[i] < ratings[i-1])
                {
                    sum = sum + down;
                    down++;
                    i++;
                }

                if(down > peak)
                {
                    sum = sum + (down - peak);
                }
            }

            return sum;
        }
    };