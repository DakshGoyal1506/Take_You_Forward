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
//         ListNode* deleteMiddle(ListNode* head) {

//             if (head == NULL || head->next == NULL)
//             {
//                 return NULL;
//             }

//             ListNode *slow = head, *fast = head;

//             while(fast->next->next && fast->next->next->next)
//             {
//                 slow = slow->next;
//                 fast = fast->next->next; 
//             }

//             slow->next = slow->next->next;

//             return head;
            
//         }
//     };

class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {

            if (head == NULL || head->next == NULL)
            {
                return NULL;
            }

            ListNode *slow = head, *fast = head, *prev = NULL;

            while(fast != NULL && fast->next != NULL)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next; 
            }

            prev->next = slow->next;

            return head;
            
        }
    };