#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {

            sort(deck.begin(), deck.end());

            queue<int> q;
            int n = deck.size();

            q.push(deck[n-1]);

            for(int i = n - 2; i >= 0; i--)
            {
                int x = q.front();
                q.pop();
                q.push(x);
                q.push(deck[i]);
            }
            
            vector<int> ans(n, 0);

            for(int i = n - 1; i >= 0; i--)
            {
                ans[i] = q.front();
                q.pop();
            }

            return ans;
        }
    };