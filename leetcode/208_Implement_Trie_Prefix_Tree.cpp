#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        TrieNode()
        {
            isEndOfWord = false;
        }
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* node = root;
            for(char c : word)
            {
                if(!node->children[c]) node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isEndOfWord = true;
        }
        
        bool search(string word) {

            TrieNode* node = root;
            for(char c : word)
            {
                if(!node->children[c]) return false;
                node = node->children[c];
            }
            return node->isEndOfWord;
        }
        
        bool startsWith(string prefix) {
            TrieNode* node = root;
            for(char c : prefix)
            {
                if(!node->children[c]) return false;
                node = node->children[c];
            }
            return true;
        }
    };