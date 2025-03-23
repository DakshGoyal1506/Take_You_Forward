#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here

        int count = 0;
        Node *cur = head;

        while(count < pos)
        {
            cur = cur->next;
            count++;
        }

        if(cur->next == NULL)
        {
            Node *temp = new Node(data);
            temp->prev = cur;
            cur->next = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = cur->next;
            cur->next->prev = temp;
            temp->prev = cur;
            cur->next = temp;
        }

        return head;

    }
};