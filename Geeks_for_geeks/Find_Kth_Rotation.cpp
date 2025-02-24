#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// The solution below is right now according to me
// also verfied by chatgpt, i donot know why is it not working

class Solution{

    public:
    int findKRotation(vector<int>& arr){
        return -1;
    }

    // public:
    // int findKRotation(vector<int>& arr){
    //     int n = arr.size();
    //     int low = 0, high = n - 1;
        
    //     if(arr[low] <= arr[high])
    //     {
    //         return 0;
    //     }

    //     while (low <= high)
    //     {
    //         int mid = (low + high) / 2;

    //         int next = (mid + 1) % n;
    //         int prev = (mid + n - 1) % n;

    //         if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
    //         {
    //             return mid;
    //         }

    //         if(arr[low] <= arr[mid])
    //         {
    //             low = mid + 1;
    //         }
    //         else
    //         {
    //             high = mid - 1;
    //         }
    //     }

    //     return 0;
        
    // }

    // public:
    // int findKRotation(vector<int> &arr) {
    //     // Code Here
    //     int n = arr.size();
    //     int low = 0, high = n - 1;
    //     int ans = INT_MAX;
    //     int index = -1;

    //     while(low <= high)
    //     {
    //         int mid = (low + high) / 2;

    //         if(arr[low] < arr[high])
    //         {
    //             if(ans > arr[low])
    //             {
    //                 index = low;
    //                 ans = arr[low];
    //                 return index;
    //             }
    //         }

    //         if(arr[low] < arr[mid])
    //         {
    //             if(ans > arr[low])
    //             {
    //                 index = low;
    //                 ans = arr[low];
    //             }
    //             low = mid + 1;
    //         }
    //         else
    //         {
    //             if(ans > arr[mid])
    //             {
    //                 index = mid;
    //                 ans = arr[mid];
    //             }
    //             high = mid - 1;
    //         }
    //     }

    //     return index;
    // }
};