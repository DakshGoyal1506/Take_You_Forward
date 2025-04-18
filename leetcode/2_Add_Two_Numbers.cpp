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

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode();      // dummy head
            ListNode* curr  = dummy;
            int carry = 0;
    
            // loop until both lists are exhausted and no carry remains
            while (l1 || l2 || carry) {
                int x = l1 ? l1->val : 0;
                int y = l2 ? l2->val : 0;
                int sum = carry + x + y;
                carry = sum / 10;
    
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
    
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
    
            return dummy->next;
        }
    };

// class Solution {
//     public:
//         ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//             int a, b, sum, rem;

//             a = l1 ->val;
//             l1 = l1->next;
//             b = l2 -> val;
//             l2 = l2->next;
//             sum = a + b;
//             rem = sum % 10;
//             sum = sum / 10;

//             ListNode *head = new ListNode(rem);
//             ListNode *curr = head;

//             while(l1 || l2 || sum)
//             {
//                 if(l1)
//                 {
//                     a = l1->val;
//                     l1 = l1->next;
//                 }
//                 else
//                 {
//                     a = 0;
//                 }
//                 if(l2)
//                 {
//                     b = l2->val;
//                     l2 = l2->next;
//                 }
//                 else
//                 {
//                     b = 0;
//                 }

//                 sum = sum + a + b;
//                 rem = sum % 10;
//                 sum = sum / 10;

//                 curr->next = new ListNode(rem);

//                 curr = curr->next;
//             }

//             return head;
            
//         }
//     };