#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string decodeString(string s) {

            stack<int> num;
            stack<char> charStack;
            string ans;

            for(int i = 0; i < s.length(); i++)
            {
                int count = 0;

                if(s[i] >='0' && s[i] <= '9')
                {
                    while(s[i] >= '0' && s[i] <= '9')
                    {
                        count = count * 10 + (s[i] - '0');
                        i++;
                    }
                    i--;
                    num.push(count);
                }
                else if(s[i] == ']')
                {
                    string temp; 

                    int rep = num.top();
                    num.pop();
                    
                    while(charStack.top() != '[')
                    {
                        temp = charStack.top() + temp;
                        charStack.pop();
                    }
                    charStack.pop();

                    string pattern;

                    for(int j = 0; j < rep; j++)
                    {
                        pattern = pattern.append(temp);
                    }

                    for(int j = 0; j < pattern.length(); j++)
                    {
                        charStack.push(pattern[j]);
                    }
                }
                else charStack.push(s[i]);
            }

            while(!charStack.empty())
            {
                ans = charStack.top() + ans;
                charStack.pop();
            }

            return ans;
        }
    };