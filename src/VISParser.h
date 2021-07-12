#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "VISInfo.h"
#include "VISTypes.h"
#include "VISUtils.h"
#pragma once

class VISParser {
 public:
  VISParser();
  ~VISParser();
  // Opens .vis file
  void OpenFile(std::string path);
  void CloseFile();
  // Parses open file

 protected:
  void Prepare();
  void Parse();

 private:
  // Methods
  void DetermineTypeFromLine(std::vector<std::string> tokens);
  // Properties
  std::vector<std::string> tokens;
  std::ifstream *file;
  bool is_opened;
  visl_types data;
};
