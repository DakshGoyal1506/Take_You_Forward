#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {

            return sumSubarrayMax(nums) - sumSubarrayMin(nums);
            
        }
    
    private:
        long long sumSubarrayMin(vector<int>& nums)
        {
            stack<int> st;
            int n = nums.size();
            vector<int> left(n), right(n);

            for(int i = 0; i < n; i++)
            {
                while(!st.empty() && nums[st.top()] > nums[i])
                {
                    st.pop();
                }
                left[i] = st.empty() ? i + 1 : i - st.top();
                st.push(i);
            }

            while(!st.empty())
            {
                st.pop();
            }

            for(int i = n - 1; i >= 0; i--)
            {
                while(!st.empty() && nums[st.top()] >= nums[i])
                {
                    st.pop();
                }
                right[i] = st.empty() ? n - i: st.top() - i;
                st.push(i);
            }

            long long ans = 0;

            for(int i = 0; i < n; i++)
            {
                ans = ans + (long long) nums[i] * left[i] * right[i];
            }

            return ans;
        }

        long long sumSubarrayMax(vector<int>& nums)
        {
            stack<int> st;
            int n = nums.size();
            vector<int> left(n), right(n);

            for(int i = 0; i < n; i++)
            {
                while(!st.empty() && nums[st.top()] < nums[i])
                {
                    st.pop();
                }
                left[i] = st.empty() ? i + 1 : i - st.top();
                st.push(i);
            }

            while(!st.empty())
            {
                st.pop();
            }

            for(int i = n - 1; i >= 0; i--)
            {
                while(!st.empty() && nums[st.top()] <= nums[i])
                {
                    st.pop();
                }
                right[i] = st.empty() ? n - i: st.top() - i;
                st.push(i);
            }

            long long ans = 0;

            for(int i = 0; i < n; i++)
            {
                ans = ans + (long long) nums[i] * left[i] * right[i];
            }

            return ans;
        }
    };