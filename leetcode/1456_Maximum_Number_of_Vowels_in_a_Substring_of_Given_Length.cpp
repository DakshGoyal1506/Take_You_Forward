#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int maxVowels = 0, currentVowels = 0;

        // Count vowels in the first window of size k
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }
        maxVowels = currentVowels;

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
            if (isVowel(s[i - k])) {
                currentVowels--;
            }
            maxVowels = max(maxVowels, currentVowels);
        }

        return maxVowels;
    }
};