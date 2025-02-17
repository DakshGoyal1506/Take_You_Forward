#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {

            int sum = 0, count = 0;
            unordered_map<int, int> prefixFreq;
            prefixFreq[0] = 1;

            for(int num : nums)
            {
                sum = sum + num;

                if(prefixFreq.find(sum - k) != prefixFreq.end())
                {
                    count = count + prefixFreq[sum - k];
                }
                prefixFreq[sum] = prefixFreq[sum] + 1;
            }

            return count;
            
        }
    };