# Scrabble Word Finder (Trie vs. Min-Heap)

A high-performance C++ tool designed to find the 10 highest-scoring Scrabble words from a hand of 7 letters. This project serves as a performance benchmark to compare the efficiency of **Trie-based search** versus a **Min-Heap** for ranking results.

## 📂 Project Structure

* `main.cpp`: The entry point that handles user input and runs the performance benchmarks.
* `Trie.h/cpp`: Implementation of the Trie data structure for efficient word lookup.
* `MinHeap.h/cpp`: Implementation of a Min-Heap to track the top 10 highest-scoring words.
* `Dictionary.h/cpp`: Handles reading and processing the Scrabble dictionary.
* `scrabbleDictionary.csv`: The dataset containing valid words and their scoring data.

## 🚀 How to Run

### 1. Compile the Project
Use a C++ compiler (like `g++`) to link all source files:

```bash
g++ -std=c++11 main.cpp MinHeap.cpp Trie.cpp Dictionary.cpp -o ScrabbleFinder
```

1. Build using the code above
2. cd to the folder that contains scrabbleDictionary.csv.
3. Run:
./build/DSA_Trie_Heap
or, if you used g++:
./ScrabbleFinder
Windows (same folder as the CSV):
build\DSA_Trie_Heap.exe
4. Enter up to 7 letters when prompted, no spaces. Use ! for a blank. Example: AREIG!P.
5. Output includes 10 Best Words (heap), then Trie Runtime and Min Heap Runtime in microseconds. Choose 1 for another rack or 2 to exit.