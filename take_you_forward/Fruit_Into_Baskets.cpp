#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
      int totalFruits(vector<int>& fruits){

          //your code goes here

        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int,int> mp;
        int MaxLength = 0;

        while(right < n)
        {
            mp[fruits[right]]++;

            while(mp.size() > 2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            if(mp.size() <= 2)
            {
                MaxLength = max(MaxLength, right - left + 1);
            }
            right++;
        }

        return MaxLength;
      }
  };