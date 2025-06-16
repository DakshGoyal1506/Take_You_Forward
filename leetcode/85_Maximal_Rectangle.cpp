#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {

            int n = matrix.size();
            if (n == 0) return 0;

            int m = matrix[0].size();

            vector<vector<int>> prefixSum(n, vector<int>(m));

            for(int j = 0; j < m; j++)
            {
                int sum = 0;
                for(int i = 0; i < n; i++)
                {

                    if(matrix[i][j] == '1') sum = sum + 1;
                    else sum = 0;

                    prefixSum[i][j] = sum;
                }
            }  
            
            int maxArea = 0;

            for(int i = 0; i < n; i++)
            {
                int area = largestRectangleArea(prefixSum[i]);

                maxArea = max(maxArea, area);
            }

            return maxArea;
            
        }
    
    private:
        int largestRectangleArea(vector<int>& heights){

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