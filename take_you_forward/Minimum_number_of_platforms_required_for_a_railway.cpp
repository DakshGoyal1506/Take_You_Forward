#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here

        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int required = 1, platfrom = 1;
        int i = 1, j = 0;

        while(i < n && j < n)
        {
            if(Arrival[i] <= Departure[j])
            {
                required++;
                i++;
            }
            else
            {
                required--;
                j++;
            }

            platfrom = max(platfrom, required);
        }
        return platfrom;
    }
};