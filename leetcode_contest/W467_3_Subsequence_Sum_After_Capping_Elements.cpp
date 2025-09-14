#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = (int)nums.size();
        // frequencies of exact values 1..n
        vector<int> cnt(n + 1, 0);
        for (int v : nums) if (v >= 1 && v <= n) cnt[v]++;

        // ge[x] = number of elements >= x
        vector<int> ge(n + 2, 0);
        for (int x = n; x >= 1; --x) ge[x] = ge[x + 1] + cnt[x];

        const int KMAX = 4000; // constraints guarantee k <= 4000
        bitset<KMAX + 1> base; // achievable sums using elements with value < current x
        base.reset();
        base[0] = 1;

        vector<bool> ans(n, false);

        for (int x = 1; x <= n; ++x) {
            // temp = achievable sums using values < x, then adding all elements >= x as value x
            bitset<KMAX + 1> temp = base;

            int copies = ge[x]; // number of copies of value x in capped array
            if (copies > 0 && x <= k) {
                int use = min(copies, k / x);
                int p = 1;
                while (use > 0) {
                    int take = min(p, use);
                    int shift = take * x;
                    if (shift > k) break;
                    temp |= (temp << shift);
                    use -= take;
                    p <<= 1;
                    if (temp[k]) break; // early exit
                }
            }

            ans[x - 1] = temp[k];

            // advance base to include exact values equal to x (for next iterations)
            int exact = cnt[x];
            if (exact > 0 && x <= k) {
                int use = min(exact, k / x);
                int p = 1;
                while (use > 0) {
                    int take = min(p, use);
                    int shift = take * x;
                    if (shift > k) break;
                    base |= (base << shift);
                    use -= take;
                    p <<= 1;
                }
            }
        }

        return ans;
    }
};

// class Solution {
//     public:
//         vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {

//             unordered_set<int> st;
//             int n = nums.size();
//             int x = 1;
//             vector<bool> ans;
//             bool flag = false;

//             for(;x <= n; x++)
//             {
//                 st.clear();
//                 flag = false;
//                 for(int num : nums)
//                 {
//                     int temp = min(num, x);

//                     if(st.find(k - temp) != st.end())
//                     {
//                         flag = true;
//                         break;
//                     }
//                     st.insert(temp);
//                 }
//                 if(flag) ans.push_back(true);
//                 else ans.push_back(false);
//             }
//             return ans;
//         }
// };