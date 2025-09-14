#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

            unordered_set<string> exact(wordlist.begin(), wordlist.end());

            unordered_map<string, string> lowercase;
            unordered_map<string, string> vowels;

            auto replaceVowels = [] (const string& word)
            {
                string pattern = "";

                for(char c : word)
                {
                    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    {
                        pattern = pattern + "*";
                    }
                    else pattern = pattern + c;
                }
                return pattern;
            };

            for(auto& word : wordlist)
            {
                string lowercase_word = word;
                transform(lowercase_word.begin(), lowercase_word.end(),
                            lowercase_word.begin(), ::tolower);

                if(lowercase.find(lowercase_word) == lowercase.end())
                {
                    lowercase[lowercase_word] = word;
                }

                string vowelpattern = replaceVowels(lowercase_word);
                if(vowels.find(vowelpattern) == vowels.end())
                {
                    vowels[vowelpattern] = word;
                }
            }

            vector<string> ans;

            for(auto& query : queries)
            {
                if(exact.find(query) != exact.end())
                {
                    ans.emplace_back(query);
                    continue;
                }

                string lowercase_word = query;
                transform(lowercase_word.begin(), lowercase_word.end(),
                            lowercase_word.begin(), ::tolower);
                
                if(lowercase.find(lowercase_word) != lowercase.end())
                {
                    ans.emplace_back(lowercase[lowercase_word]);
                    continue;
                }
                
                string vowelpattern = replaceVowels(lowercase_word);
                if(vowels.find(vowelpattern) != vowels.end())
                {
                    ans.emplace_back(vowels[vowelpattern]);
                    continue;
                }

                ans.emplace_back("");
            }
            return ans;
        }
};