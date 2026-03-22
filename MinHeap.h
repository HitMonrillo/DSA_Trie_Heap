//
// Created by Murilo Matos on 3/9/26.
// Implemented by Luisa
#include <string>
#include <vector>
using namespace std;
#ifndef MINHEAP_H
#define MINHEAP_H

//struct for holding the word and its score together as a unit
struct WordScore {
    string word;
    int score;
};

class MinHeap {
private:
    vector<WordScore> heap;
    //internal helpers:
    void heapifyDown(int index);
    void heapifyUp(int index);
public:
    MinHeap(); //constructor, initializes an empty heap
    void insert(string word, int score); //adds a word to the heap
    void extractMin(); //removes the root (lowest score)
    void printHeap(); // prints all 10 words at the end
    WordScore peek(); //returns the root without removing it
    int size(); //returns the size of the heap
};

#endif //MINHEAP_H
