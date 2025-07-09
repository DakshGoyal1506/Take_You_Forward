#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {

            int size = sandwiches.size();
            // initialize queue with students vector via a deque
            queue<int> s(deque<int>(students.begin(), students.end()));
            queue<int> sand(deque<int>(sandwiches.begin(), sandwiches.end()));
            s.push(-1);

            while(!s.empty())
            {
                int x = s.front();
                int y = sand.front();

                if(x == -1)
                {
                    if(sand.size() == size) return s.size() - 1;
                    else
                    {
                        size = sand.size();
                        s.pop();
                        s.push(x);
                        continue;
                    }
                }

                if(x == y)
                {
                    s.pop();
                    sand.pop();
                }
                else
                {
                    s.pop();
                    s.push(x);
                }
            }
            return 0;
            
        }
    };