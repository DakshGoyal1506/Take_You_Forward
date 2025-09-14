#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {

        vector<char> arr;
        unordered_set<char> st = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        for(char c : s)
        {
            if(st.find(c) != st.end())
            {
                arr.push_back(c);
            }
        }

        sort(arr.begin(), arr.end());

        int n = s.size();
        int j = 0;

        for(int i = 0; i < n; i++)
        {
            if(st.find(s[i]) != st.end())
            {
                s[i] = arr[j];
                j++;
            }
        }
        
        return s;
    }
};