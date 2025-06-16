#include <bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//         int celebrity(vector<vector<int>> &M){

//             int rows = M.size();
//             int cols = M[0].size();
//             int left = 0;
//             int right = cols - 1;

//             while(left < rows && cols >= 0)
//             {
//                 if(M[left][right] == 1)
//                 {
//                     left++;
//                 }
//                 else
//                 {
//                     right --;
//                 }
//             }

//             if(left == rows || right == -1) return -1;

//             int i = 0;

//             while(i < cols)
//             {
//                 if(M[left][i] == 1) return -1;
//             }
//             i = 0;

//             while(i < rows)
//             {
//                 if(i == right)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     if(M[i][right] == 0)
//                     {
//                         return -1;
//                     }
//                 }
//             }

//             return left;
            
//         }
// };


class Solution
{
public:
    int celebrity(vector<vector<int>> &M){

        int n = M.size();

        vector<int> iKnow(n, 0), KnowMe(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] == 1)
                {
                    iKnow[i]++;
                    KnowMe[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(KnowMe[i] == (n - 1) && iKnow[i] == 0)
            {
                return i;
            }
        }

        return -1;
        
    }
};
