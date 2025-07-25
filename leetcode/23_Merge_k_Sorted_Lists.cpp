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
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            auto cmp = [](ListNode* a, ListNode* b){
                return a->val > b->val;
            };

            priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

            for(auto node: lists)
            {
                if(node) pq.push(node);
            }

            ListNode *dummy = new ListNode();
            ListNode *tail = dummy;

            while(!pq.empty())
            {
                ListNode* node = pq.top();
                pq.pop();
                tail->next = node;
                tail = tail ->next;

                if(node->next)
                {
                    pq.push(node->next);
                }
            }
            
            return dummy->next;
        }
    };