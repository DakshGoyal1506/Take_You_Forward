#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSubstr(string& s, int k) {
        int n = s.length();
        int count = 0;
        
        // For each starting position
        for(int i = 0; i < n; i++) {
            // Use fixed size array for lowercase letters
            vector<int> freq(26, 0);
            int distinct = 0;
            int j = i;
            
            // Sliding window
            while(j < n) {
                // Add current character
                freq[s[j] - 'a']++;
                if(freq[s[j] - 'a'] == 1) {
                    distinct++;
                }
                
                // If we have exactly k distinct characters
                if(distinct == k) {
                    count++;
                }
                
                // If we have more than k distinct characters, break
                if(distinct > k) {
                    break;
                }
                
                j++;
            }
        }
        
        return count;
    }
};