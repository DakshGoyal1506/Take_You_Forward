#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices)
        {
            if(price < minPrice)
            {
                minPrice = price;
            }
            else
            {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
        
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int n = prices.size();
//         int max = 0;

//         for(int i = 0; i < n ; i++)
//         {
//             for(int j = i; j < n; j++)
//             {
//                 if(max < (prices[j] - prices[i]))
//                 {
//                     max = prices[j] - prices[i];
//                 }
//             }
//         }

//         return max;
        
//     }
// };