#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int key, value;
        Node* next;
        Node* prev;

        Node()
        {
            key = value = -1;
            next = prev = NULL;
        }

        Node(int k, int val)
        {
            key = k;
            value = val;
            next = prev = NULL;
        }

};

class LRUCache {

    private:
        map <int, Node*> mpp;
        int cap;
        Node* head;
        Node* tail;

        void addNode(Node* node)
        {
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;
        }

        void removeNode(Node* node)
        {
            Node* p = node ->prev;
            Node* n = node->next;

            p->next = n;
            n->prev = p;
        }

        void moveNodeToHead(Node* node)
        {
            removeNode(node);
            addNode(node);
        }

        Node* popTail(){
            Node* res = tail->prev;
            removeNode(res);
            return res;
        }

    public:
        LRUCache(int capacity) {

            cap = capacity;
            mpp.clear();

            head = new Node();
            tail = new Node();

            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {

            auto it = mpp.find(key);

            if(it == mpp.end()) return -1;

            Node* node = it->second;
            
            moveNodeToHead(node);
            return node->value;
        }
        
        void put(int key, int value) {

            auto it = mpp.find(key);

            if(it != mpp.end())
            {
                Node* node = it->second;
                node->value = value;
                moveNodeToHead(node);
            }
            else
            {
                Node* node = new Node(key, value);
                mpp[key] = node;
                addNode(node);

                if(mpp.size() > cap)
                {
                    Node* tailNode = popTail();
                    removeNode(tailNode);
                    mpp.erase(tailNode->key);
                    delete tailNode;
                }
            }
            
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */