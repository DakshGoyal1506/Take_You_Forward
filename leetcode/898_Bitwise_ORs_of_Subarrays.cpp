#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& arr) {

            unordered_set<int> st;
            int curr = 0;
            int n = arr.size();

            for(int i = 0; i < n; i++)
            {
                curr = curr | arr[i];
                int sub = 0;

                for(int j = i ; j >= 0; j--)
                {
                    sub = sub | arr[j];
                    st.insert(sub);

                    if(curr == sub) break;
                }
            }
            return st.size();
        }
    };