#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> partition(string s) {

            vector<vector<string>> ans;
            vector<string> pal;
            helper(0, s, pal, ans);
            return ans;
            
        }

    private:

        void helper(int index, string s, vector<string>& pal, vector<vector<string>>& ans)
        {
            if(index == s.size())
            {
                ans.push_back(pal);
                return;
            }

            for(int i = index; i < s.size(); i++)
            {
                if (isPalindrome(s, index, i))
                {
                    pal.push_back(s.substr(index, i - index + 1));
                    helper(i + 1, s, pal, ans);
                    pal.pop_back();
                }
            }
        }

        bool isPalindrome(string s, int start, int end)
        {
            while(start <= end)
            {
                if(s[start++] != s[end--])
                {
                    return false;
                }
            }

            return true;
        }
    };