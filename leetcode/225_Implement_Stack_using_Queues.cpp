#include <bits/stdc++.h>
using namespace std;

class MyStack {

        queue <int> q;
    public:
        MyStack() {
        }
        
        void push(int x) {
            int n = q.size();
            q.push(x);

            for(int i = 0; i < n; i++)
            {
                q.push(q.front());
                q.pop();
            }
            
        }
        
        int pop() {

            if(empty())
            {
                return -1;
            }

            int num = q.front();
            q.pop();
            return num;
            
        }
        
        int top() {
            if(empty())
            {
                return -1;
            }
            return q.front();
        }
        
        bool empty() {
            
            return q.size() == 0;
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */