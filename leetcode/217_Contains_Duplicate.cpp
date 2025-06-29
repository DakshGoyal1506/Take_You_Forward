#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         bool containsDuplicate(vector<int>& nums) {

//             unordered_set<int> st;
//             int n = nums.size();

//             for(int i = 0; i < n; i++)
//             {
//                 if(st.find(nums[i]) != st.end()) return true;
//                 else st.insert(nums[i]);;
//             }

//             return false;
//         }
//     };

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {

            unordered_set<int> st;
            
            for(int x : nums)
            {
                st.insert(x);
            }

            return st.size() < nums.size();
        }
    };