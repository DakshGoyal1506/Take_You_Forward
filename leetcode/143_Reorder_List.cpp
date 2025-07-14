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
        void reorderList(ListNode* head) {

            ListNode* slow = head;
            ListNode* fast = head;

            while(fast->next != NULL && fast->next->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* secondHalf = slow->next;
            slow->next = nullptr;

            ListNode* prev = NULL;

            while(secondHalf)
            {
                ListNode* temp = secondHalf->next;
                secondHalf->next = prev;
                prev = secondHalf;
                secondHalf = temp;
            }

            secondHalf = prev;
            ListNode* firstHalf = head;

            while(secondHalf)
            {
                ListNode* temp = secondHalf->next;
                secondHalf->next = firstHalf->next;
                firstHalf->next = secondHalf;

                firstHalf = secondHalf->next;
                secondHalf = temp;
            }
            
        }
    };