#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {

            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            vector<int> ds;
            helper(0, ans, ds, nums);
            return ans;
            
        }

    private:

        void helper(int index, vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums)
        {
            ans.push_back(ds);

            for(int i = index; i < nums.size(); i++)
            {
                if(i > index && nums[i] == nums[i - 1]) continue;

                ds.push_back(nums[i]);
                helper(i + 1, ans, ds, nums);
                ds.pop_back();
            }
        }
        // void helper(int index, vector<vector<int>>& ans, vector<int>& nums)
        // {

        //     for(int i = index; i < nums.size(); i ++)
        //     {
        //         if(i > index && nums[i] == nums[i - 1]) continue;
        //         append(i, ans, nums);
        //     }

        //     return ;
        // }

        // void append(int index, vector<vector<int>>& ans, vector<int>& nums)
        // {
        //     vector<vector<int>> ans1 = ans;

        //     for(auto & a : ans1)
        //     {
        //         a.push_back(nums[index]);
        //     }

        //     ans.insert(ans.end(), ans1.begin(), ans1.end());

        //     return;
        // }
    };