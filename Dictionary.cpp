#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool isValidLength(const string& currWord) {                      //Weed out all words with length greater than 8
  if (currWord.length() > 8) {
    return false;
  }
  return true;
}

bool canForm(const string& word, const string& playerLetters) {
    int available[26] = {0};
    int blanks = 0;
    for (int i = 0; i < playerLetters.length(); i++) {
        if (playerLetters[i] == '!')
            blanks++;
        else
            available[toupper(playerLetters[i]) - 'A']++;
    }
    for (int i = 0; i < word.length(); i++) {
        int index = toupper(word[i]) - 'A';
        if (available[index] > 0)
            available[index]--;
        else if (blanks > 0)
            blanks--;
        else
            return false;
    }
    return true;
}

vector<string> Dictionary::loadDictionary (const string& filename, const string& userLetters) {
  vector<string> editedDict = {};
  
  ifstream ogDict(filename);                  //Load dictionary file into ogDict
  if (!ogDict.is_open()) {
    cout << "Could not open dictionary file: " << filename << endl;
    return editedDict;
  }
  
  string currWord;    
  while (getline(ogDict, currWord)) {                        //Read each word into currWord
    if (!currWord.empty() && currWord.back() == '\r') {      //Remove trailing '\r's from file
      currWord.pop_back();
    }
    if (isValidLength(currWord) && canForm(currWord, userLetters)) {                              //If currWord length and chars are valid,
      editedDict.push_back(currWord);                                                     //add to dict
    }
  }
  
  ogDict.close();
  return editedDict;
}
