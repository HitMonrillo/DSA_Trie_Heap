cmake_minimum_required(VERSION 3.29)
project(DSA_Trie_Heap)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_Trie_Heap main.cpp
        DataLoader.h
        MinHeap.h
        MinHeap.cpp
        Trie.cpp
        DataLoader.cpp)
