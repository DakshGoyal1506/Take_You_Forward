#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minLength(string s) {

            stack<char> st;

            for(char c : s)
            {
                if(st.empty())
                {
                    st.push(c);
                    continue;
                }

                if(st.top() == 'A' && c == 'B')
                {
                    st.pop();
                    continue;
                }
                else if(st.top() == 'C' && c == 'D')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    st.push(c);
                }
            }
            return st.size();
        }
    };