#include <QString>
#include <fstream>
#include <iostream>
#include <string>

#include "parser/info.h"
#include "parser/types.h"
#pragma once

class VISLParser {
  VISLParser();
  ~VISLParser();

 public:
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
