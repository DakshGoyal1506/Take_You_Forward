#include <bits/stdc++.h>
using namespace std;

class MinStack {

        stack <pair<int, int>> s;

    public:
        MinStack() {
            
        }
        
        void push(int val) {

            int min;

            if(s.empty())
            {
                min = val;
            }
            else
            {
                min = std::min(s.top().second, val);
            }
            
            s.push({val, min});
        }
        
        void pop() {
            s.pop();
            return;
        }
        
        int top() {
            return s.top().first;
        }
        
        int getMin() {
            return s.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */