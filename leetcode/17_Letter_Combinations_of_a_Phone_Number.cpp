#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if(digits.empty()) return {};

            static const vector<string> mapping = {
                "", "", "abc", "def", "ghi", "jkl",
                "mno", "pqrs", "tuv", "wxyz"
            };

            vector<string> ans;
            string curr;
            helper(0, digits, mapping, curr, ans);
            return ans;
            
        }
    
    private:

        void helper(int index, const string& digits, const vector<string>& mapping, string& curr, vector<string>& ans)
        {
            if(index == digits.size())
            {
                ans.push_back(curr);
                return;
            }

            int d = digits[index] - '0';

            for(char c : mapping[d])
            {
                curr.push_back(c);
                helper(index + 1, digits, mapping, curr, ans);
                curr.pop_back();
            }
        }
    };