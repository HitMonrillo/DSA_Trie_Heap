#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <chrono>
#include <cctype>
#include "MinHeap.h"
#include "Dictionary.h"
using namespace std;
using namespace std::chrono;
//Helpers:
int calculateScore(string word) {
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int total = 0;
    for (int i =0 ; i <word.length(); i++) {
        if (word[i] == '!')
            continue;
        total += scores[toupper(word[i])- 'A'];
    } return total;
}

bool canForm(string word, string playerLetters) {
    int available[26] = {0};
    int blanks = 0;
    for (int i = 0; i < playerLetters.length(); i++) {
        if (playerLetters[i] == '!') {
            blanks++;
        }
        else {
            available[toupper(playerLetters[i]) - 'A']++;
        }
    }
        for (int i = 0; i <word.length(); i++) {
            int index = toupper(word[i]) - 'A';
            if (available[index] > 0) {
                available[index]--;
            }
            else if (blanks > 0) {
                blanks--;
            }
            else {
                return false;
            }
        }
        return true;
    }


    int main() {
        cout << "--------------------\n" << "Scrabble Word Finder\n" << "---------------------" << endl;

        bool running = true;
        while (running) {
            string userLetters = "";
            int userContinue;
            vector<string> bestWords = {};
            bool validWord = true;

            cout << "Enter your letters (don't include spaces, use \"!\" to denote blank tiles, ex. \"AREIG!P\"): " << endl;
            cin >> userLetters;

            for (int i=0; i<userLetters.length(); i++) {                                            //Checking validity of input
                if (!isalpha(userLetters[i]) && (userLetters[i] != '!')) {
                    validWord = false;
                }
            }

            while (userLetters.length() != 7 || !validWord) {
                cout << "Invalid input, please enter 7 letters with no spaces, use \"!\" to denote blank tiles: " << endl;            //Printing error message & repeating prompt if input is invalid
                cin >> userLetters;
                validWord = true;

                for (int i=0; i<userLetters.length(); i++) {
                    if (!isalpha(userLetters[i]) && (userLetters[i] != '!')) {
                        validWord = false;
                    }
                }
            }

            Dictionary dict;
            vector<string> dictionary = dict.loadDictionary("scrabbleDictionary.csv", userLetters);

            auto startTrie = high_resolution_clock::now();                                            //Timing trie
            //Function that runs trie here, store result in vector bestWords
            auto stopTrie = high_resolution_clock::now();

            auto startHeap = high_resolution_clock::now();                                            //Timing min heap
            MinHeap minHeap;
            for (int i =0; i <dictionary.size(); i++) {
                string word = dictionary[i];
                if (canForm(word, userLetters)) {
                    int score = calculateScore(word);
                    if (minHeap.size()< 10)
                        minHeap.insert(word, score);
                    else if (score > minHeap.peek().score){
                        minHeap.extractMin();
                        minHeap.insert(word, score);
                    }
                }
            }
            auto stopHeap = high_resolution_clock::now();

            cout << "10 Best Words: " << endl;                                                         //Printing results
            minHeap.printHeap();

            auto trieDuration = duration_cast<microseconds>(stopTrie-startTrie);                       //Printing runtimes
            cout << "Trie Runtime: " << trieDuration.count() << "microseconds" << endl;
            auto heapDuration = duration_cast<microseconds>(stopHeap-startHeap);
            cout << "Min Heap Runtime: " << heapDuration.count() << "microseconds" << endl;

            cout << "\nDo you want to continue?" << endl;                                              //Printing continue menu
            cout << "1. Try another set of letters" << endl;
            cout << "2. Exit" << endl;
            cin >> userContinue;

            while (userContinue != 1 && userContinue != 2) {                                           //Printing error message & repeating prompt if input is invalid
                cout << "Invalid selection, please try again." << endl;
                cout << "1. Try another set of letters" << endl;
                cout << "2. Exit" << endl;
                cin >> userContinue;
            }

            if (userContinue == 2) {                                                                    //Exiting program if 2 is entered
                running = false;
            }
        }
        return 0;
    }
