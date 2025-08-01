#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        bool isVowel(char c)
        {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
    public:
        int countBalanced(vector<string>& arr) {
            // code here

            unordered_map<int, int> freq;
            int diff = 0, result = 0;
            freq[0] = 1;

            for(auto& s : arr)
            {
                int d = 0;
                for(char c : s)
                {
                    d += isVowel(c) ? 1 : -1;   // fix: ensure ternary is applied correctly
                }

                diff = diff + d;

                if(freq.find(diff) != freq.end())
                {
                    result = result + freq[diff];
                }
                freq[diff]++;
            }
            return result;
        }
  };