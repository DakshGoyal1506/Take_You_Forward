#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.length() != word2.length()) return false;

        vector<int> st1(26, 0);
        vector<int> st2(26, 0);

        int n = word1.size();

        for(int i = 0; i < n; i++)
        {
            st1[word1[i] - 'a']++;
            st2[word2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if((st1[i] == 0) != (st2[i] == 0)) return false;
        }
        
        vector<int> freq1, freq2;
        for(int i = 0; i < 26; i++)
        {
            if(st1[i] > 0) freq1.push_back(st1[i]);
            if(st2[i] > 0) freq2.push_back(st2[i]);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};