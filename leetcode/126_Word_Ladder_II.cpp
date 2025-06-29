#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

            vector<vector<string>> ans;

            queue<vector<string>> q;
            unordered_set<string> st(wordList.begin(), wordList.end());

            vector<string> toErase;
            q.push({beginWord});

            while(!q.empty())
            {
                int size = q.size();

                for(int i = 0; i < size; i++)
                {
                    vector<string> seq = q.front();
                    q.pop();
                    string word = seq.back();

                    if(word == endWord)
                    {
                        if(ans.empty()) ans.push_back(seq);
                        else if(ans.back().size() == seq.size()) ans.push_back(seq);
                    }

                    for(int j = 0; j < word.size(); j++)
                    {
                        char original = word[j];
                        for(char k = 'a'; k <= 'z'; k++)
                        {
                            word[j] = k;
                            if(st.find(word) != st.end())
                            {
                                seq.push_back(word);
                                q.push(seq);
                                seq.pop_back();
                                toErase.push_back(word);
                            }
                        }
                        word[j] = original;
                    }
                }

                for(auto x : toErase) st.erase(x);
                toErase.clear();

                if(!ans.empty()) break;
            }
            return ans;
        }
    };