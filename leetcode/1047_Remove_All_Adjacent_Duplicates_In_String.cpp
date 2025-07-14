#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeDuplicates(string s) {

            stack<char> st;

            for(char c : s)
            {
                if(st.empty())
                {
                    st.push(c);
                    continue;
                }

                if(st.top() == c)
                {
                    st.pop();
                    continue;
                }
                else
                {
                    st.push(c);
                }
            }

            string ans;

            while(!st.empty())
            {
                char c = st.top();
                ans.push_back(c);
                st.pop();
            }

            reverse(ans.begin(), ans.end());

            return ans;
            
        }
    };