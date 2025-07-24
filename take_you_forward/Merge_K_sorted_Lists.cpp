#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
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
        ListNode* mergeKSortedLists(vector<ListNode*> &head) {

            auto cmp = [](ListNode* a, ListNode* b){
                return a->val > b->val;
            };

            priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

            for(auto x: head)
            {
                pq.push(x);
            }

            ListNode* dummy = new ListNode(-1);
            ListNode* tail = dummy;

            while(!pq.empty())
            {
                ListNode* node = pq.top();
                pq.pop();
                tail->next = node;
                tail = tail->next;

                if(node->next)
                {
                    pq.push(node->next);
                }
            }
            return dummy->next;
        }
    };