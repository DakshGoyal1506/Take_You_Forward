#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {

            if (num.length() <= k) return "0";

            if (k == 0) return num;

            stack<char> st;
            int n = num.length();

            int i = 0;
            
            while(i < n && k)
            {
                if(st.empty() || st.top() <= num[i])
                {
                    st.push(num[i++]);
                }
                else
                {
                    st.pop();
                    k--;
                }
            }

            while(k && !st.empty())
            {
                st.pop();
                k--;
            }

            string ans = "";

            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());

            ans = ans + num.substr(i);

            int j = 0;

            while(j < ans.size() && ans[j] == '0')
            {
                j++;
            }

            ans = ans.substr(j);

            return ans.empty()? "0" : ans;
            
        }
    };