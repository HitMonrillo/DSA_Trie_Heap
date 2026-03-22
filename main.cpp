#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <chrono>
#include <cctype>
using namespace std;

int main() {
    cout << "--------------------\n" << "Scrabble Word Finder\n" << "---------------------" << endl;

    bool running = true;
    while (running) {
        string userLetters = "";
        int userContinue;
        vector<string> bestWords = {};
        bool validWord = true;
        
        cout << "Enter your letters (don't include spaces, use "!" to denote blank tiles, ex. "AREIG!P"): " << endl;
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

        //functions for reading in CSV and processing it will go here
        
        auto startTrie = high_resolution_clock::now();                                            //Timing trie
        //Function that runs trie here, store result in vector bestWords
        auto stopTrie = high_resolution_clock::now();

        auto startHeap = high_resolution_clock::now();                                            //Timing min heap
        //Function that runs heap here
        auto stopHeap = high_resolution_clock::now();
        
        cout << "10 Best Words: ";                                                                 //Printing results
        for (int j=0; j<bestWords.size();j++) {
            if (j==0) {
                cout << bestWords[j];
            } else {
                cout << ", " << bestWords[j];
            }
        }

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
