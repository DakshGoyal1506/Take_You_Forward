#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            stack<string> st;

            string ans = "";

            for(char c : s)
            {
                if(c == ' ')
                {
                    if(!ans.empty())
                    {
                        st.push(ans);
                        ans = "";
                    }
                }
                else
                {
                    ans = ans + c;
                }
            }

            while(!st.empty())
            {
                if(!ans.empty())
                {
                    ans = ans + " ";
                }
                ans = ans + st.top();
                st.pop(); 
            }

            return ans;
            
        }
    };