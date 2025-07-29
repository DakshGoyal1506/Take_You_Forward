#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
        void dfs(int index, int n, vector<int>& nums, int curr, int& count, int maxNum)
        {
            if (index == n) {
                if (curr == maxNum) ++count;
                return;
            }

            dfs(index + 1, n, nums, curr, count, maxNum);
            dfs(index + 1, n, nums, curr | nums[index], count, maxNum);
        }
    public:
        int countMaxOrSubsets(vector<int>& nums) {

            int maxNum = 0;
            int count = 0;

            for(int x : nums) maxNum = maxNum | x;
            dfs(0, nums.size(), nums, 0, count, maxNum);
            return count;
            
        }
    };