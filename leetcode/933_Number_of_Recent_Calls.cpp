#include<bits/stdc++.h>
using namespace std;

class RecentCounter {

    private:
        queue<int> q;

    public:
        RecentCounter() {
            q.empty();
        }
        
        int ping(int t) {
            q.push(t);

            while(q.front() < t - 3000)
            {
                q.pop();
            }
            return q.size();
        }
    };