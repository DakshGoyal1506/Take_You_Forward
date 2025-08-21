#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {

        // Use string as an in-place stack to reduce memory overhead
        string res;
        res.reserve(s.size());

        for (char c : s) {
            if (c == '*') {
                if (!res.empty()) res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};


// class Solution {
// public:
//     string removeStars(string s) {

//         stack<char> st;

//         for(char c: s)
//         {
//             if(c == '*')
//             {
//                 if(!st.empty()) st.pop();
//                 else continue;
//             }
//             else
//             {
//                 st.push(c);
//             }
//         }

//         string ans = "";

//         while(!st.empty())
//         {
//             ans = ans + st.top();
//             st.pop();
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };