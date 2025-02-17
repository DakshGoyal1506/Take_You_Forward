#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return 0;  // If less than 2 elements, no valid subarray exists.

        int maxSum = 0;
        stack<int> s;
        
        // Traverse each element in the array.
        for (int x : arr) {
            // While the stack is not empty and the top of the stack is greater than or equal to x,
            // it means that for the element at the top, x can serve as the candidate for the second smallest.
            while (!s.empty() && s.top() >= x) {
                maxSum = max(maxSum, s.top() + x); // Update maxSum with the sum of the current pair.
                s.pop();  // Remove the element as x is a better candidate to pair with future elements.
            }
            // After the loop, if the stack is not empty, then the current element x can also form a valid pair
            // with the new stack top (which is less than x).
            if (!s.empty()) {
                maxSum = max(maxSum, s.top() + x);
            }
            // Push the current element x onto the stack.
            s.push(x);
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {616, 362, 166, 599, 656, 599};
    cout << sol.pairWithMaxSum(arr) << endl;  // Expected output: 1255
    return 0;
}



// // #include <iostream>
// // #include <bits/stdc++.h>
// // #include <vector>
// // #include <algorithm>
// // #include <unordered_map>
// // #include <stack>
// // using namespace std;

// // class Solution{
// //     public:

// //     int pairWithMaxSum(vector<int> &arr)
// //     {

// //         int n = arr.size();

// //         if(n < 2) return 0;

// //         vector<int> nextsmaller(n, n);
// //         vector<int> previoussmaller(n, -1);
// //         stack<int> s;

// //         for(int i = 0; i < n; i++)
// //         {
// //             while(!s.empty() && (arr[s.top()] > arr[i]))
// //             {
// //                 nextsmaller[s.top()] = i;
// //                 s.pop();
// //             }
// //             s.push(i);
// //         }

// //         while(!s.empty())
// //         {
// //             s.pop();
// //         }

// //         for(int i = n - 1; i >= 0; i--)
// //         {
// //             while(!s.empty() && (arr[s.top()] > arr[i]))
// //             {
// //                 previoussmaller[s.top()] = i;
// //                 s.pop();
// //             }
// //             s.push(i);
// //         }

// //         int maxscore = 0;

// //         for(int i = 0; i < n; i++)
// //         {
// //             int left = previoussmaller[i] + 1;
// //             int right = nextsmaller[i] - 1;

// //             if(left < i && i < right)
// //             {
// //                 int secondsmaller = max(arr[left], arr[right]);
// //                 maxscore = max(maxscore, arr[i] + secondsmaller);
// //             }
// //             else if(left < i)
// //             {
// //                 maxscore = max(maxscore, arr[i] + arr[left]);
// //             }
// //             else if(right > i)
// //             {
// //                 maxscore = max(maxscore, arr[i] + arr[right]);
// //             }
// //         }

// //         return maxscore;
// //     }
// // };

// // #####################################################
// // below is attempt by chatgpt correct the attempt provided above
// // but the solution provided at the top is the best
// // ######################################################

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// class Solution {
// public:
//     // Build a sparse table for range maximum queries.
//     // st[i][j] will store the maximum value in arr[i ... i + 2^j - 1].
//     vector<vector<int>> buildSparseTable(const vector<int>& arr) {
//         int n = arr.size();
//         int K = floor(log2(n)) + 1;
//         vector<vector<int>> st(n, vector<int>(K));
//         for (int i = 0; i < n; i++) {
//             st[i][0] = arr[i];
//         }
//         for (int j = 1; j < K; j++) {
//             for (int i = 0; i + (1 << j) <= n; i++) {
//                 st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
//             }
//         }
//         return st;
//     }
    
//     // Precompute logarithms so that we can answer RMQ in O(1).
//     vector<int> buildLogTable(int n) {
//         vector<int> logTable(n+1);
//         logTable[1] = 0;
//         for (int i = 2; i <= n; i++) {
//             logTable[i] = logTable[i/2] + 1;
//         }
//         return logTable;
//     }
    
//     // Answer the maximum query in the range [L, R] using the sparse table.
//     int queryRMQ(const vector<vector<int>>& st, const vector<int>& logTable, int L, int R) {
//         int j = logTable[R - L + 1];
//         return max(st[L][j], st[R - (1 << j) + 1][j]);
//     }
    
//     int pairWithMaxSum(vector<int> &arr) {
//         int n = arr.size();
//         if (n < 2) return 0;
        
//         // Compute nextsmaller and previoussmaller arrays.
//         vector<int> nextsmaller(n, n);
//         vector<int> previoussmaller(n, -1);
//         stack<int> s;
        
//         // Next smaller element for each index.
//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && arr[s.top()] > arr[i]) {
//                 nextsmaller[s.top()] = i;
//                 s.pop();
//             }
//             s.push(i);
//         }
//         while (!s.empty()) s.pop();
        
//         // Previous smaller element for each index.
//         for (int i = n - 1; i >= 0; i--) {
//             while (!s.empty() && arr[s.top()] > arr[i]) {
//                 previoussmaller[s.top()] = i;
//                 s.pop();
//             }
//             s.push(i);
//         }
        
//         // Build the RMQ structure.
//         vector<vector<int>> st = buildSparseTable(arr);
//         vector<int> logTable = buildLogTable(n);
        
//         int maxScore = 0;
        
//         // For each index, assume arr[i] is the minimum of a subarray.
//         // Its maximal span is from L to R.
//         for (int i = 0; i < n; i++) {
//             int L = previoussmaller[i] + 1;
//             int R = nextsmaller[i] - 1;
            
//             // The span must contain at least 2 elements.
//             if (R - L + 1 < 2) continue;
            
//             int candidatePartner = -1;  // Will hold the best candidate for the second smallest.
            
//             // Check the left part [L, i-1] if non-empty.
//             if (i - 1 >= L) {
//                 candidatePartner = max(candidatePartner, queryRMQ(st, logTable, L, i - 1));
//             }
//             // Check the right part [i+1, R] if non-empty.
//             if (i + 1 <= R) {
//                 candidatePartner = max(candidatePartner, queryRMQ(st, logTable, i + 1, R));
//             }
            
//             if (candidatePartner != -1) {
//                 maxScore = max(maxScore, arr[i] + candidatePartner);
//             }
//         }
        
//         return maxScore;
//     }
// };

// int main() {
//     Solution sol;
//     // Example test case:
//     vector<int> arr = {616, 362, 166, 599, 656, 599};
//     cout << sol.pairWithMaxSum(arr) << endl;  // Expected output: 1255
//     return 0;
// }
