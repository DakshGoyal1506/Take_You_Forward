#include <string>
using namespace std;

class Solution {
    public:
        string removeOuterParentheses(string s) {
            
            string ans;
            int balance = 0;

            for(char c : s)
            {
                if(c == '(')
                {
                    if(balance > 0)
                    {
                        ans.push_back(c);
                    }
                    balance ++;
                }
                else
                {
                    balance --;
                    if(balance > 0)
                    {
                        ans.push_back(c);
                    }
                }
            }

            return ans;
        }
    };