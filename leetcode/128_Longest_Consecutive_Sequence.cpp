#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n == 0)
        {
            return 0;
        }

        int count = 1, maxCount = 0;

        for(int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if(nums[i] == (nums[i - 1] + 1) )
            {
                count ++;
            }
            else
            {
                maxCount = max(maxCount, count);
                count = 1;
            }
            
        }

        return max(maxCount, count);
        
    }
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {

//         if(nums.empty())
//         {
//             return 0;
//         }

//         unordered_set<int> st(nums.begin(), nums.end());
//         int longeststreak = 0;

//         for(int num : nums)
//         {
//             if(st.find(num - 1) == st.end())
//             {
//                 int currentNum = num;
//                 int currentStreak = 1;

//                 while(st.find(currentNum+1) != st.end())
//                 {
//                     currentNum = currentNum + 1;
//                     currentStreak++;
//                 }
//                 longeststreak = max(longeststreak, currentStreak);
//             }
//         }

//         return longeststreak;
        
//     }
// };
