#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {

            unordered_map<int, int> mp;

            for(int x : hand)
            {
                mp[x]++;
            }

            sort(hand.begin(), hand.end());

            for(int card: hand)
            {
                if(mp.count(card))
                {
                    for(int i = card; i < card + groupSize; i++)
                    {
                        if(!mp.count(i)) return false;
                        else
                        {
                            mp[i]--;
                            if(mp[i] == 0) mp.erase(i);
                        }
                    }
                }
            }
            return true;
        }
    };