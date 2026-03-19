
#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary {
public:
  Dictionary();
  ~Dictionary();

  vector<tuple<string, int>> loadDictionary(string filename);
  bool isValidLength(string currWord);
  bool hasValidChars(string currWord);
  int valueGenerator(string currWord);
};

#endif DICTIONARY_H
