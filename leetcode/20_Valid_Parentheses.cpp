#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> q;

            for(char a : s)
            {
                if(a == '(' || a == '{' || a == '[')
                {
                    q.push(a);
                }
                else
                {
                    if (q.empty()
                       || (a == ')' && q.top() != '(')
                       || (a == '}' && q.top() != '{')
                       || (a == ']' && q.top() != '[')) 
                    {
                        return false;
                    }
                    else
                    {
                        q.pop();
                    }
                }
            }

            return q.empty();
            
        }
    };