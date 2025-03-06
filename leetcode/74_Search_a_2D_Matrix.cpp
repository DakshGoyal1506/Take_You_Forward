#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {

            int n = matrix.size();
            int m = matrix[0].size();

            int low = 0, high = n - 1;
            int ans = -1;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(matrix[mid][0] <= target)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if (ans == -1) {
                return false;
            }

            if(matrix[ans][0] == target)
            {
                return true;
            }

            low = 0;
            high = m - 1;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(matrix[ans][mid] == target)
                {
                    return true;
                }

                if(matrix[ans][mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;   
                }
            }

            return false;
            
        }
    };