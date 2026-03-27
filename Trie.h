//
// Created by Murilo Matos on 3/9/26.
//

#ifndef TRIE_H
#define TRIE_H

#include <array>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    array<TrieNode*, 26> children;
    bool isEnd;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void Destroy(TrieNode* node);

public:
    Trie();
    ~Trie();


    void insert(const string& word);
    bool contains(const string& word);

    vector<string> findWordsPossible(const string& LettersGiven) const;
};



#endif //TRIE_H
