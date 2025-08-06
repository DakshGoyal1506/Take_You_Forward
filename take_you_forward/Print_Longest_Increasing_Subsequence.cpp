#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> longestIncreasingSubsequence(vector<int>& arr) {

            int n = arr.size();
            vector<int> dp(n, 0);
            vector<int> parent(n, 0);
            int lastIndex = 0;
            int maxLen = 0;

            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
                for(int j = 0; j < i; j++)
                {
                    if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
                    {
                        parent[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }

                if(dp[i] > maxLen)
                {
                    lastIndex = i;
                    maxLen = dp[i];
                }
            }

            int i = lastIndex;
            vector<int> ans;
            while(parent[i] != i)
            {
                ans.push_back(arr[i]);
                i = parent[i];
            }
            ans.push_back(arr[i]);

            reverse(ans.begin(), ans.end());
            return ans;
        
    }
};

// class Solution {

//     private:
//         void helper(int index, int prev, vector<int>& arr, vector<int> curr, vector<int>& ans, int& maxLen)
//         {
//             if(index == arr.size() - 1)
//             {
//                 if(prev == -1 || arr[index] > arr[prev])
//                 {
//                     curr.push_back(arr[index]);
//                 }

//                 if(curr.size() > maxLen)
//                 {
//                     ans = curr;
//                     maxLen = curr.size();
//                 }
//                 return;
//             }

//             if(prev == -1 || arr[index] > arr[prev])
//             {
//                 curr.push_back(arr[index]);
//                 helper(index + 1, index, arr, curr, ans, maxLen);
//                 curr.pop_back();
//             }
//             helper(index+1, prev, arr, curr, ans, maxLen);
//         }
//     public:
//         vector<int> longestIncreasingSubsequence(vector<int>& arr) {

//             /*
//             Normal recursion
//             store each sub arrary in temp
//             store max length
//             at end temp.len
//             if len > max erase and store new
//             else return
//             */

//             vector<int> ans, curr;
//             int maxLen = 0;
//             helper(0, -1, arr, curr, ans, maxLen);
//             return ans;
     
//     }
// };