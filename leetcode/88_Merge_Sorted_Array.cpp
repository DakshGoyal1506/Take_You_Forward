#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

            // int pointer1 = n + m - 1;
            int pointer2 = m - 1;
            int pointer3 = n - 1;

            for(int i = m + n - 1; i >= 0; i--)
            {
                if(pointer2 >= 0 && pointer3 >= 0)
                {
                    if(nums1[pointer2] >= nums2[pointer3])
                    {
                        nums1[i] = nums1[pointer2];
                        pointer2--;
                    }
                    else
                    {
                        nums1[i] = nums2[pointer3];
                        pointer3--;
                    }
                }
                else if(pointer2 >= 0)
                {
                    nums1[i] = nums1[pointer2];
                    pointer2--;
                }
                else if(pointer3 >= 0)
                {
                    nums1[i] = nums2[pointer3];
                    pointer3--;
                }
            }
            
        }
    };