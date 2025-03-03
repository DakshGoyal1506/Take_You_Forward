#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int NumStudents(vector<int> arr, int n, int max)
{
    int students = 1;
    int pages = 0;

    for(int book : arr)
    {
        if(pages + book <= max)
        {
            pages = pages + book;
        }
        else
        {
            students ++;
            pages = book;
        }
    }

    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        cout << low << " " << high << endl;
        int mid = (low + high) / 2;
        int students = NumStudents(arr, n, mid);

        if(students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
    
}