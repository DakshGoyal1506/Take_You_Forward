#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // implement greedy planting to check if we can place n flowers
        int count = 0;
        for (int i = 0; i < flowerbed.size() && count < n; ++i) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i-1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                ++count;
            }
        }
        return count >= n;
    }
};