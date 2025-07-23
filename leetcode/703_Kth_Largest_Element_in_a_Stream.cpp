#include <bits/stdc++.h>
using namespace std;

class KthLargest {

    private:
        priority_queue<int, vector<int>, greater<int>> pq;
        int x;
    public:
        KthLargest(int k, vector<int>& nums) {

            x = k;

            for(int i = 0; i < nums.size(); i++)
            {
                // if(pq.size() < k) pq.push(nums[i]);
                
                // else if(pq.size() == k && nums[i] > pq.top())
                // {
                //     pq.pop();
                //     pq.push(nums[i]);
                // }
                pq.push(nums[i]);
            }

            while(pq.size() > k)
            {
                pq.pop();
            }
            
        }
        
        int add(int val) {

            if(pq.size() < x)
            {
                pq.push(val);

                if(pq.size() == x) return pq.top();
                else return -1;
            }

            if(val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }

            return pq.top();
        }
    };