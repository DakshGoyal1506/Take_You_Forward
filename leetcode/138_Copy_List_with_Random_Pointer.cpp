#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    public:
        Node* copyRandomList(Node* head) {
            
            if(head == NULL)
            {
                return head;
            }

            Node* curr = head;

            while(curr)
            {
                Node* temp = new Node(curr->val);
                temp->next = curr->next;
                curr->next = temp;
                curr = temp->next;
            }

            curr = head;

            while(curr)
            {
                curr->next->random = curr->random ? curr->random->next : NULL;
                curr = curr->next->next;
            }

            curr = head;

            Node* copyHead = head->next;

            while(curr)
            {
                Node* copy = curr->next;
                curr->next = copy->next;
                copy->next = copy->next ? copy->next->next : NULL;
                curr = curr->next;
            }

            return copyHead;

        }
    };