
#ifndef DATALOADER_H
#define DATALOADER_H

class DataLoader {
public:
  DataLoader();
  ~DataLoader();

  vector<tuple<string, int>> loadDictionary(string filename);
  bool isValidLength(string currWord);
  bool hasValidChars(string currWord);
  int valueGenerator(string currWord);
};

#endif DATALOADER_H
