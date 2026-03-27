
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

class Dictionary {
public:
  std::vector<std::string> loadDictionary(const std::string& filename, const std::string& userLetters);
};

#endif // DICTIONARY_H 
