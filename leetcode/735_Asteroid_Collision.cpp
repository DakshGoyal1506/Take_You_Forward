#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {

            stack<int> st1;
            int n = asteroids.size();

            for(int i = 0; i < n; i++)
            {
                if(st1.empty())
                {
                    st1.push(asteroids[i]);
                    continue;
                }

                if(st1.top() > 0 && asteroids[i] < 0)
                {
                    if(abs(st1.top()) == abs(asteroids[i]))
                    {
                        st1.pop();
                        continue;
                    }
                    else if(abs(st1.top()) > abs(asteroids[i]))
                    {
                        continue;
                    }
                    else
                    {
                        st1.pop();
                        i--;
                        continue;
                    }
                }
                else
                {
                    st1.push(asteroids[i]);
                }
            }

            int m = st1.size();
            vector<int> ans(m, 0);

            for(int i = m - 1; i >= 0; i--)
            {
                ans[i] = st1.top();
                st1.pop();
            }
            
            return ans;
        }
    };