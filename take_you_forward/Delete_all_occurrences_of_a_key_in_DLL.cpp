#include<bits/stdc++.h>
using namespace std;

// Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {

        ListNode *curr = head;

        while(curr)
        {
            if(curr->val == target)
            {
                if(curr == head)
                {
                    head = head->next;
                }
                else
                {
                    ListNode *prev = curr->prev;
                    ListNode *next = curr->next;

                    if(prev)
                    {
                        prev->next = next;
                    }
                    if(next)
                    {
                        next->prev = prev;
                    }
                    delete curr;
                    curr = next;
                }
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};