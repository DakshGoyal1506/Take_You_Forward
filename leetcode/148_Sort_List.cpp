// #include <bits/stdc++.h>
// using namespace std;

// //  Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
//     public:
//         ListNode* sortList(ListNode* head) {

//             if(head == NULL || head->next == NULL)
//             {
//                 return head;
//             }

//             //Middle node

//             ListNode *slow = head, *fast = head->next;

//             while(fast && fast->next)
//             {
//                 slow = slow->next;
//                 fast = fast->next->next;
//             }

//             ListNode *left = head;
//             ListNode *right = slow->next;
//             slow->next = NULL;

//             left = sortList(left);
//             right = sortList(right);

//             ListNode *dummy = new ListNode(-1);
//             ListNode *temp = dummy;

//             while(left && right)
//             {
//                 if(left->val <= right->val)
//                 {
//                     temp->next = left;
//                     left = left->next;
//                 }
//                 else
//                 {
//                     temp->next = right;
//                     right = right->next;
//                 }

//                 temp = temp->next;
//             }

//             if(left == NULL)
//             {
//                 temp->next = right;
//             }
//             else
//             {
//                 temp->next = left;
//             }

//             return dummy->next;
            
//         }
//     };

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        // Split list into two halves
        ListNode *slow = head, *fast = head->next;  
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        
        // Recursively sort each half
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        // Merge the sorted halves
        return merge(left, right);
    }
    
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        
        while(left && right) {
            if(left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return dummy.next;
    }
};