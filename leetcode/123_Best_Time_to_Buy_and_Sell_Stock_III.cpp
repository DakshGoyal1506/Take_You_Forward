#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {

            int n = prices.size();
            vector<int> left(n, 0), right(n, 0);

            int minP = prices[0];
            for(int i = 1; i < n; i++)
            {
                minP = min(minP, prices[i]);
                left[i] = max(left[i - 1], prices[i] - minP);
            }

            int maxP = prices[n-1];
            for(int i = n - 2; i >= 0; i--)
            {
                maxP = max(maxP, prices[i]);
                right[i] = max(right[i+1], maxP - prices[i]);
            }

            int ans = 0;

            for(int i = 0; i < n; i++)
            {
                ans = max(ans, left[i] + right[i]);
            }
            return ans;
        }
    };

// class Solution {
//     public:
//         int maxProfit(vector<int>& prices) {

//             int n = prices.size();
//             vector<int> ans(n, 0);
//             stack<int> s;

//             for(int i = n - 1; i >= 0; i--)
//             {
//                 if(!s.empty())
//                 {
//                     while(s.top() < prices[i]) s.pop();

//                     if(!s.empty())
//                     {
//                         ans[i] = s.top() - prices[i];
//                     }
//                 }
//                 s.push(prices[i]);
//             }
            
//             int max1 = -1, max2 = -1;

//             for(int x : ans)
//             {
//                 if(x >= max1)
//                 {
//                     max2 = max1;
//                     max1 = x;
//                 }
//                 else if(x > max2)
//                 {
//                     max2 = x;
//                 }
//             }

//             return max1 + max2;
//         }
//     };