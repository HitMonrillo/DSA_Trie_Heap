#include "Dictionary.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>

Dictionary::Dictionary() {
  vector<string> validWords = {};
}

Dictionary::~Dictionary(){}

bool isValidLength(string currWord) {                      //Weed out all words with length greater than 8
  if (currWord.length() > 8) {
    return false;
  }
  return true;
}

bool hasValidChars(string currWord, vector<char> userChars) {   //Compare dictionary word to the user's letters,
  vector<char> dictLetters;                                     //if there's one or no differences, return true
  for (int i=0; i<currWord.length(); i++) {
    dictLetters.push_back(currWord[i]);
  }
  for (int j=0; j<userChars.size(); j++) {
    if (userChars[j]

      //FINISH
      //DON'T FORGET '!'

}

int valueGenerator(string currWord) {
  unordered_map<char,int> letterVals = {('A',1), ('B',3), ('C',3), ('D',2), ('E',1), 
  ('F',4), ('G',2), ('H',4), ('I',1), ('J',8), ('K',5), ('L',1), ('M',3), ('N',1),
  ('0',1), ('P',3), ('Q',10), ('R',1), ('S',1), ('T',1), ('U',1), ('V',4), ('W',4),
  ('X',8), ('Y',4), ('Z',10), ('!',0)};
  int currVal;
  int sum = 0;

  for (int i=0; i<currWord.length(); i++) {
    int currVal = letterVals[toupper(currWord[i])];
    sum += currVal;
  }
  return sum;
}

unordered_map<string, int> Dictionary::loadDictionary (string filename, string userLetters) {
  unordered_map<string,int> editedDict = {};
  bool validLen;
  bool validChar;
  
  ifStream ogDict("scrabbleDictionary.csv");                  //Load dictionary file into ogDict
  string currWord;  
  
  vector<char> userChars;                                    //Create vector of chars to hold user's letters
  for (int i=0; i<userLetters.length(); i++){
    userChars.push_back(userLetters[i]);
  }
  
  while (getline(ogDict, currWord)) {                        //Read each word into currWord
    validLen = isValidLength(currWord);
    validChar = hasValidChars(currWord, userChars);

    if (validLen && validChar) {                              //If currWord length and chars are valid,
      int currVal = valueGenerator(currWord);                 //calculate value and add tuple to editedDict
      editedDict.insert({currWord, currVal});
    }
  }
  
  ogDict.close();
  return editedDict;
}
