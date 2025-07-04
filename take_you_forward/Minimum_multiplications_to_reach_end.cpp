#include<bits/stdc++.h>
using namespace std;

#define P pair<int, int>

class Solution{
    public:
        int minimumMultiplications(vector<int> &arr, int start, int end) {

            if(start == end) return 0;

            int n = arr.size();

            vector<int> maxSteps(1e5, INT_MAX);
            int mod = 100000;

            priority_queue<P> pq;
            pq.push({0, start});

            maxSteps[start] = 0;

            while(!pq.empty())
            {
                auto x = pq.top();
                pq.pop();

                int step = x.first;
                int val = x.second;

                for(int i = 0; i < n; i++)
                {
                    int num = (val * arr[i]) % mod;

                    if(num == end) return step + 1;

                    if(step + 1 < maxSteps[num])
                    {
                        maxSteps[num] = step + 1;

                        pq.push({step + 1, num});
                    }
                }
            }
            return -1;
        }
    };
    