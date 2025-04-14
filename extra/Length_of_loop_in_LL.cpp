#include<bits/stdc++.h>
using namespace std;


// Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
    public:
        int findLengthOfLoop(ListNode *head) {
    
            if(head == NULL || head->next == NULL)
            {
                return 0;
            }
    
            ListNode *slow = head, *fast = head;
    
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
    
                if(slow == fast)
                {
                    int count = 1;
                    ListNode *curr = slow;
                    slow = slow->next;
    
                    while(slow != curr)
                    {
                        count ++;
                        slow = slow -> next;
                    }
    
                    return count;
                }
            }

            return 0;
    
        }
    };