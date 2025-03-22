#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here

        

        Node *cur = head;

        while(cur->next != NULL)
        {
            cur = cur->next;
        }

        Node *temp = new Node(x); 
        cur->next = temp;

        return head;
    }
};