#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {

            int n = nums.size();
            int candidates1 = 0, candidates2 = 0;
            int count1 = 0, count2 = 0;

            for(int num : nums)
            {
                if(candidates1 == num)
                {
                    count1 ++;
                }
                else if(candidates2 == num)
                {
                    count2 ++;
                }
                else if(count1 == 0)
                {
                    candidates1 = num;
                    count1 = 1;
                }
                else if(count2 == 0)
                {
                    candidates2 = num;
                    count2 = 1;
                }
                else
                {
                    count1 --;
                    count2 --;
                }
            }

            count1 = 0;
            count2 = 0;
            for(int num : nums)
            {
                if(candidates1 == num)
                {
                    count1 ++;
                }
                else if(candidates2 == num)
                {
                    count2 ++;
                }
            }

            vector<int> ans;
            if(count1 > n/3)
            {
                ans.push_back(candidates1);
            }
            if(count2 > n/3)
            {
                ans.push_back(candidates2);
            }

            return ans;
            
        }
    };