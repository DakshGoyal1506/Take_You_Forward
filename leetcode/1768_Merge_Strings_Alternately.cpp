#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {

            int n = word1.size();
            int m = word2.size();
            int i = 0, j = 0;
            bool flag = true;
            string ans = "";

            while(i < n && j < m)
            {
                if(flag)
                {
                    ans.push_back(word1[i]);
                    i++;
                }
                else
                {
                    ans.push_back(word2[j]);
                    j++;
                }
                flag = !flag;
            }

            if(i == n)
            {
                ans.append(word2.substr(j));
            }
            else if(j == m)
            {
                ans.append(word1.substr(i));
            }
            return ans;
        }
    };