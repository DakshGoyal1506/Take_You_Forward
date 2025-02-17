#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:

        int result = 0;

        void dfs(int freq[26])
        {
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] > 0)
                {
                    freq[i]--;
                    result++;
                    dfs(freq);
                    freq[i]++;
                }
            }
        }

        int numTilePossibilities(string tiles) {

            int freq[26] = {0};

            for(char c : tiles)
            {
                freq[c - 'A'] ++;
            }
            dfs(freq);
            return result;
            
        }
    };