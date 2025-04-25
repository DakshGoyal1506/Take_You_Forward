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
        ListNode* rotateRight(ListNode* head, int k) {

            if(head == NULL || head -> next == NULL)
            {
                return head;
            }

            ListNode* curr = head;

            int n = 0;

            while(curr)
            {
                curr = curr -> next;
                n++;
            }

            k = k % n;

            ListNode* ahead = head;

            while(ahead && k)
            {
                ahead = ahead -> next;
                k--;
            }

            if(ahead == NULL)
            {
                return head;
            }

            curr = head;

            while(ahead->next != NULL)
            {
                ahead = ahead -> next;
                curr = curr -> next;
            }

            ahead -> next = head;
            head = curr->next;
            curr->next = NULL;

            return head;
            
        }
    };