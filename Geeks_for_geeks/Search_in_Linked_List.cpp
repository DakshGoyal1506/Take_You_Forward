#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here

        Node *cur = head;

        while(cur != NULL)
        {
            if(cur->data == key)
            {
                return true;
            }
            cur = cur->next;
        }

        return false;
    }
};