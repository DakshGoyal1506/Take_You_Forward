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

        ListNode* reverseLL(ListNode *head)
        {
            ListNode* curr = head;
            ListNode* prev = NULL;

            while(curr != NULL)
            {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
        }

        ListNode* kthNode(ListNode* head, int k)
        {
            k--;

            while(head != NULL && k)
            {
                head = head -> next;
                k--;
            }

            return head;
        }

        ListNode* reverseKGroup(ListNode* head, int k) {

            ListNode* curr = head;

            ListNode* prevNode = NULL;

            while(curr)
            {
                ListNode* kth = kthNode(curr, k);
                
                if(kth == NULL)
                {
                    if(prevNode)
                    {
                        prevNode -> next = curr;
                    }
                    break;
                }

                ListNode* nextNode = kth->next;

                kth->next = NULL;

                reverseLL(curr);

                if(curr == head)
                {
                    head = kth;
                }
                else
                {
                    prevNode -> next = kth;
                }

                prevNode = curr;
                curr = nextNode;
            }

            return head;
            
        }
    };