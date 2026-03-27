//
// Created by Murilo Matos on 3/9/26.
//

#include "Trie.h"
#include <iostream>
#include <string>
using namespace std;

TrieNode::TrieNode() : children{}, isEnd(false) {
    for (int i = 0; i < children.size(); i++) {
        children[i] = nullptr; //initializing everything to null
    }
}

void Trie::Destroy(Trie *node) {
    if (node == nullptr) {
        return;
    }
}
