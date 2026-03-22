//
// Created by Murilo Matos on 3/9/26.
// Implemented by Luisa
#include "MinHeap.h"
#include <iostream>
using namespace std;

//constructor
MinHeap::MinHeap() {
}

//created a WordScore, pushes it to the end of the vector, then calls heapifyUp on the last index
void MinHeap::insert(string word, int score) {
    WordScore newWord = {word, score};
    heap.push_back(newWord);
    heapifyUp(heap.size()-1);
}

void MinHeap::heapifyUp(int index) {
    int parent = (index - 1) /2;
    if (index > 0 && heap[index].score < heap[parent].score) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}
void MinHeap::heapifyDown(int index) {
    int left = 2 * index +1;
    int right = 2 * index +2;
    int smallest = index;
    if (left < heap.size() && heap[left].score < heap[smallest].score) {
        smallest = left;
    }
    if (right < heap.size() && heap[right].score < heap[smallest].score) {
        smallest = right;
    }
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::extractMin() {
    heap[0]= heap.back();
    heap.pop_back();
    heapifyDown(0);
}

WordScore MinHeap::peek() {
    return heap[0];
}

int MinHeap::size() {
    return heap.size();
}
void MinHeap::printHeap() {
    for (int i = 0; i< heap.size(); i ++) {
        cout << heap[i].word << " (" << heap[i].score << ")" <<endl;
    }
}