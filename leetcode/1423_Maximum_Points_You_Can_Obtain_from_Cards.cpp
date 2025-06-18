#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {

            int n = cardPoints.size();

            int currWindowSum = 0;

            for(int i = 0; i < n - k; i++)
            {
                currWindowSum = currWindowSum + cardPoints[i];
            }

            int sum = currWindowSum;

            for(int i = n-k; i < n; i++)
            {
                sum = sum + cardPoints[i];
            }

            int ans = sum - currWindowSum;
            int left = 0, right = n - k;

            while(right < n)
            {
                currWindowSum = currWindowSum - cardPoints[left] + cardPoints[right];

                ans = max(ans, sum - currWindowSum);
                right++;
                left++;
            }

            return ans;
        }
    };