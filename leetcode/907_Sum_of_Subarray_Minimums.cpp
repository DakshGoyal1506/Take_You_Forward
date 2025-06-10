#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         int sumSubarrayMins(vector<int>& arr) {

//             stack<int> st1, st2;

//             long long sum = 0;
//             const int MOD = 1e9+7;

//             for(int i = 0; i < arr.size(); i++)
//             {
//                 int min_element = INT_MAX;
//                 st1.push(arr[i]);

//                 while(!st1.empty())
//                 {
//                     int x = st1.top();
//                     st1.pop();
//                     min_element = min(min_element, x);
//                     sum = (sum + min_element) % MOD;
//                     st2.push(x);
//                 }

//                 while(!st2.empty())
//                 {
//                     st1.push(st2.top());
//                     st2.pop();
//                 }
//             }

//             return (int)(sum % MOD);
            
//         }
//     };

class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {

            int n = arr.size();
            const int MOD = 1e9+7;
            vector<int> left(n), right(n);
            stack<int> st;

            for(int i = 0; i < n; i++)
            {
                while(!st.empty() && arr[st.top()] > arr[i])
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
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }

                right[i] = st.empty() ? n - i: st.top() - i;
                st.push(i);
            }

            long long ans = 0;

            for(int i = 0; i < n; i++)
            {
                ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
            }

            return (int) ans;

        }
    };