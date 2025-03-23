#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here

        int n = arr.size();

        if(n == 0)
        {
            return NULL;
        }

        Node *head = new Node(arr[0]);

        if(n == 1)
        {
            return head;
        }

        Node *cur = head;

        for(int i = 1; i < n ; i++)
        {
            Node *temp = new Node(arr[i]);
            temp->prev = cur;
            cur->next = temp;
            cur = temp;
        }

        return head;
    }
};