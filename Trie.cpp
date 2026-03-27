//
// Created by Murilo Matos on 3/9/26.
//

#include "Trie.h"
#include <cctype>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

TrieNode::TrieNode() : children{}, isEnd(false) {
    for (int i = 0; i < children.size(); i++) {
        children[i] = nullptr; //initializing everything to null
    }
}

Trie::Trie() {
    root = new TrieNode();
}


void Trie::Destroy(TrieNode *node) {
    if (node == nullptr) {
        return;
    }
    for (int i =0; i< (int)node->children.size(); i++) {
        if (node->children[i] != nullptr) {
            Destroy(node->children[i]);
            node->children[i] = nullptr;
        }
    }
    delete node; //
}

void Trie::insert(const string &word) {
    static const regex not_letter("[^A-Za-z]");
    string cleaned = regex_replace(word, not_letter, "");

    TrieNode* current = root;
    for (int i = 0; i < cleaned.size(); i++) {
        int index = toupper((unsigned char)cleaned[i]) - 'A';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEnd = true;
}

bool Trie::contains(const string &word) {

}

Trie::~Trie() {
    Destroy(root);
    root = nullptr;
}
