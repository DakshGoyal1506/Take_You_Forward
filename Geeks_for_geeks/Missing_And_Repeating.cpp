#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long sum = 0, sumSq = 0;

        for(int x : arr)
        {
            sum = sum + x;
            sumSq = sumSq + (long long)x * x;
        }

        long long a = n * (n + 1) / 2;
        long long asq = n * (n + 1) * (2 * n + 1) / 6;

        long long diff = sum - a;
        long long diffsq = sumSq - asq;

        long long sumxy = diffsq / diff;

        int repeating = (diff + sumxy) / 2;
        // int missing = sumxy - repeating;
        int missing = repeating - (int)diff;

        return {repeating, missing};
    }
};