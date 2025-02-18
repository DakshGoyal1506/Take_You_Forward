#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // Function to count inversions in the array.
    int merge(vector<int>& arr, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        int count = 0;

        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count = count + (mid - left + 1);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergesort(vector<int>& arr, int low, int high)
    {
        int count = 0;
        
        if(low >= high)
        {
            return count;
        }
        int mid = (low + high) / 2;
        
        count = count + mergesort(arr, low, mid);
        count = count + mergesort(arr, mid + 1, high);
        count = count + merge(arr, low, mid, high);

        return count;
    }

    int inversionCount(vector<int> &arr) {

        int n = arr.size();
        return mergesort(arr, 0, n-1);
        // Your Code Here
    }
};