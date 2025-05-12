#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string curr;
            dfs(0, 0, n, curr, ans);
            return ans;
            
        }

    private:

        void dfs(int open, int close, int max, string& curr, vector<string>& ans)
        {
            if((int)curr.size() == max * 2)
            {
                ans.push_back(curr);
                return;
            }

            if(open < max)
            {
                curr.push_back('(');
                dfs(open + 1, close, max, curr, ans);
                curr.pop_back();
            }

            if(close < open)
            {
                curr.push_back(')');
                dfs(open, close + 1, max, curr, ans);
                curr.pop_back();
            }
    }


    };

// class Solution {
//     public:

//         vector<string> parenthesis(int n, int open, vector<string>& ans)
//         {
//             if(n == 1)
//             {
//                 for(auto& s : ans)
//                 {
//                     s.append("()");
//                 }
//                 return ans;
//             }

//             if(open > 0)
//             {
//                 vector<string> ans1 = ans;
//                 for(auto& s : ans1)
//                 {
//                     s.append("(");
//                 }
//                 ans1 = parenthesis(n - 1, open + 1, ans1);

//                 vector<string> ans2 = ans;
//                 for(auto& s : ans2)
//                 {
//                     s.append(")");
//                 }
//                 ans2 = parenthesis(n - 1, open - 1, ans2);

//                 ans1.insert(ans1.end(), ans2.begin(), ans2.end());

//                 return ans1;
//             }
//             else
//             {
//                 vector<string> ans1 = ans;
//                 for(auto& s : ans1)
//                 {
//                     s.append("(");
//                 }
//                 ans1 = parenthesis(n - 1, open + 1, ans1);

//                 return ans1;
//             }
//         }

//         vector<string> generateParenthesis(int n) {

//             vector<string> ans = {""};
//             return parenthesis(n, 0, ans);
            
//         }
//     };