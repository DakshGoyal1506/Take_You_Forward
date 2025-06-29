#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {

            unordered_map<string, int> wordCount;
            for(string x : words) wordCount[x]++;

            int n = s.length();
            int numOfWords = words.size();
            int left = 0, right = 0;
            vector<int> ans;
            int wordLength = words[0].size();

            for(int i = 0; i < n; i++)
            {
                unordered_map<string, int> windowCount;
                left = i;
                right = i;
                int totalCount = 0;

                while(left + (numOfWords * wordLength) <= n && right + wordLength <= n)
                {
                    string currWord = s.substr(right, wordLength);
                    right = right + wordLength;

                    if(!wordCount[currWord])
                    {
                        windowCount.clear();
                        totalCount = 0;
                        left = right;
                        continue;
                    }

                    windowCount[currWord]++;
                    totalCount++;

                    while(windowCount[currWord] > wordCount[currWord])
                    {
                        string leftWord = s.substr(left, wordLength);
                        windowCount[leftWord]--;
                        left = left + wordLength;
                        totalCount--;
                    }

                    if(totalCount == numOfWords)
                    {
                        ans.push_back(left);
                    }
                }
            }
            return ans;
        }
    };