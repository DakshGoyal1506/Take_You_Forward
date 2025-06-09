#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {

            if(head == NULL) return head;

            ListNode *curr = head->next, *prev = head;

            while(curr != NULL)
            {
                if(curr->val == val)
                {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                else
                {
                    prev = curr;
                    curr = curr -> next;
                }
            }

            if(head->val == val) return head->next;
            else return head;
            
        }
    };