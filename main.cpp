#include <iostream>
#include <string>
#include <chrono>
#include <cctype>
using namespace std;

int main() {
    cout << "--------------------\n" << "Scrabble Word Finder\n" << "---------------------" << endl;

    bool running = true;
    while (running) {
        string userLetters = "";
        int userContinue;
        array bestWords = {};
        bool validWord = false;
        
        cout << "Enter your letters (don't include spaces, ex. "AREIGHP"): " << endl;
        cin >> userLetters;

        for (int i=0; i<userLetters.length(); i++) {                                            //Checking validity of input
            if (!isalpha(userLetters[i])) {
                validWord = false;
            }
        }

        while (userLetters.length() != 7 || !validWord) {
            cout << "Invalid input, please enter 7 letters with no spaces: " << endl;            //Printing error message & repeating prompt if input is invalid
            cin >> useLetters;
           
            for (int i=0; i<userLetters.length(); i++) {
                if (!isalpha(userLetters[i])) {
                    validWord = false;
                }
            }
        }

        //functions for reading in CSV and processing it will go here
        
        auto startTrie = high_resolution_clock::now();                                            //Timing trie
        //Function that runs trie here, store result in array bestWords
        auto stopTrie = high_resolution_clock::now();

        auto startHeap = high_resolution_clock::now();                                            //Timing min heap
        //Function that runs heap here
        auto stopHeap = high_resolution_clock::now();
        
        cout << "10 Best Words: " << bestWords << endl;                                            //Printing results
        cout << "Trie Runtime: " << stopTrie << "microseconds" << endl;
        cout << "Min Heap Runtime: " << stopHeap << "microseconds" << endl;

        cout << "\nDo you want to continue?" << endl;                                              //Printing continue menu
        cout << "1. Try another set of letters" << endl;
        cout << "2. Exit" << endl;
        cin << userContinue;

        while (userContinue != 1 && userContinue != 2) {                                           //Printing error message & repeating prompt if input is invalid
            cout << "Invalid selection, please try again." << endl; 
            cout << "1. Try another set of letters" << endl;
            cout << "2. Exit" << endl;
            cin << userContinue;
        }

        if (userContinue == 2) {                                                                    //Exiting program if 2 is entered
            running = false;
        }
    }
        return 0;
}
