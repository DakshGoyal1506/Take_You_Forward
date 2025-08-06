#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

            int n = fruits.size();
            int count = 0;

            for(int i = 0; i < n; i++)
            {
                int j = 0;

                while(j < n)
                {
                    if(fruits[i] <= baskets[j])
                    {
                        count++;
                        baskets[j] = 0;
                        break;
                    }
                    j++;
                }
            }
            return n - count;
        }
    };