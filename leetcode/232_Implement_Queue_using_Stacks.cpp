#include <bits/stdc++.h>
using namespace std;

class MyQueue {

    stack <int> input, output;
    public:
        MyQueue() {
            
        }
        
        void push(int x) {

            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }

            input.push(x);

            while(!output.empty())
            {
                input.push(output.top());
                output.pop();
            }
            
        }
        
        int pop() {

            if(input.empty())
            {
                return -1;
            }

            int num = input.top();
            input.pop();
            return num;
            
        }
        
        int peek() {

            return input.top();
            
        }
        
        bool empty() {
            return input.empty();
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */