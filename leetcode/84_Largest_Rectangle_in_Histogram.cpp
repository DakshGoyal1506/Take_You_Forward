#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         int largestRectangleArea(vector<int>& heights) {

//             int maxArea = 0;
//             int n = heights.size();

//             for(int i = 0; i < n; i++)
//             {
//                 int minHeight = INT_MAX;
//                 for(int j = i; j < n; j++)
//                 {
//                     minHeight = min(minHeight, heights[j]);
//                     maxArea = max(maxArea, minHeight * (j - i + 1));
//                 }
//             }

//             return maxArea;
            
//         }
//     };

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {

            int n = heights.size();
            stack<int> st;
            vector<int> left(n, 0), right(n, 0);

            for(int i = 0; i < n; i++)
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                left[i] = st.empty() ? 0 : st.top() + 1;

                st.push(i);
            }

            while(!st.empty())
            {
                st.pop();
            }

            for(int i = n - 1; i >= 0; i--)
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                right[i] = st.empty() ? n - 1 : st.top() - 1;

                st.push(i);
            }

            int maxArea = 0;

            for(int i = 0; i < n; i++)
            {
                maxArea = max(maxArea, (right[i] - left[i] + 1) * heights[i]);
            }

            return maxArea;
        
        }
};