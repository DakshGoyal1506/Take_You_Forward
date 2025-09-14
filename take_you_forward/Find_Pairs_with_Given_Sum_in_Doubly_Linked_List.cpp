#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};


class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here

        unordered_set<int> st;
        ListNode *curr = head;
        vector<vector<int>> ans;

        while(curr)
        {
            int x = target - curr->val;

            if(st.find(x) != st.end())
            {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(curr->val);
                ans.push_back(temp);
            }
            else
            {
                st.insert(curr->val);
            }
            curr = curr->next;
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};