#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeDuplicateLetters(string s) {

            vector<int> lastIndex(26, 0);

            for(int i = 0; i < s.length(); i++)
            {
                lastIndex[s[i] - 'a'] = i;
            }

            unordered_set<int> st;
            string ans;

            for(int i = 0; i < s.length(); i++)
            {
                char c = s[i];

                if(st.find(c) != st.end()) continue;

                while(!ans.empty() && ans.back() > c && lastIndex[ans.back() - 'a'] > i)
                {
                    st.erase(ans.back());
                    ans.pop_back();
                }

                st.insert(c);
                ans.push_back(c);
            }
            return ans;
        }
    };