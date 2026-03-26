//
// Created by Murilo Matos on 3/9/26.
//

#ifndef TRIE_H
#define TRIE_H

#include <array>
#include <vector>
#include <string>

using namespace std;



class Trie {
private:
    Trie* root;

    void Destroy(Trie* node);

public:
    Trie();
    ~Trie();


    void insert(const string& word);
    bool contains(const string& word);
};



#endif //TRIE_H
