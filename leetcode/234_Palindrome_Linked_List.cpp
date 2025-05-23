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
        bool isPalindrome(ListNode* head) {
            
            if(head == NULL || head->next == NULL)
            {
                return true;
            }

            ListNode *slow = head, *fast = head;

            while(fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode *prev = NULL, *curr = slow;
            while(curr)
            {
                ListNode *temp =  curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode *first = head, *second = prev;

            while(second)
            {
                if(first->val != second->val)
                {
                    return false;
                }
                first = first->next;
                second=second->next;
            }

            return true;
        }
    };