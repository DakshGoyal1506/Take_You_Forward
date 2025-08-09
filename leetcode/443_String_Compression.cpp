#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int write = 0, read = 0;
        while (read < n) {
            char curr = chars[read];
            int count = 0;
            while (read < n && chars[read] == curr) {
                ++read;
                ++count;
            }
            chars[write++] = curr;
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) chars[write++] = c;
            }
        }
        return write;
    }
};