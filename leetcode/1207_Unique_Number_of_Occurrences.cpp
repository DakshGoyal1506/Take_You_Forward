#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        unordered_set<int> occurrenceSet;

        // Count occurrences of each element
        for (int num : arr) {
            countMap[num]++;
        }

        // Check if occurrences are unique
        for (const auto& entry : countMap) {
            if (occurrenceSet.find(entry.second) != occurrenceSet.end()) {
                return false;
            }
            occurrenceSet.insert(entry.second);
        }

        return true;
    }
};