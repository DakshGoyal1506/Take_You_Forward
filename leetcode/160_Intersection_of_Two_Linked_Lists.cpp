#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
//     public:
//         ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

//             ListNode *a1 = headA;
//             ListNode *a2 = headB;

//             while(a1 != a2)
//             {
//                 if(a1)
//                 {
//                     a1 = a1->next;
//                 }
//                 else
//                 {
//                     a1 = headB;
//                 }

//                 if(a2)
//                 {
//                     a2 = a2->next;
//                 }
//                 else
//                 {
//                     a2 = headA;
//                 }
//             }

//             return a1;
            
//         }
//     };

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            ListNode *a1 = headA;
            ListNode *a2 = headB;

            while(a1 != a2)
            {
                a1 = a1 == NULL ? headB : a1->next;
                a2 = a2 == NULL ? headA : a2->next;
            }

            return a1;
            
        }
    };