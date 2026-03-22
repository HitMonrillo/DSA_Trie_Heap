
#ifndef DICTIONARY_H
#define DICTIONARY_H

#pragma once
#include <string>
#include <vector>
using namespace std;

class Dictionary {
public:
  Dictionary();
  ~Dictionary();
  vector<string> loadDictionary(string filename, string userLetters);
};

#endif DICTIONARY_H
