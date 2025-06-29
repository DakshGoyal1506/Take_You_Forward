#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

            queue<pair<string, int>> q;
            unordered_set<string> st(wordList.begin(), wordList.end());

            q.push({beginWord, 1});
            st.erase(beginWord);

            while(!q.empty())
            {
                auto x = q.front();
                q.pop();

                string word = x.first;
                int steps = x.second;

                if(word == endWord) return steps;

                for(int i = 0; i < word.size(); i++)
                {
                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;

                        if(st.find(word) != st.end())
                        {
                            q.push({word, steps+1});
                            st.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            return 0;
        }
    };